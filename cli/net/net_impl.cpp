#include "net_impl.h"
#include <stdio.h>
#include <winsock.h>
namespace chess {
	NetImpl* NetImpl::inst_ = NULL;
	NetImpl::NetImpl()
	{
		// create a client instance.
		client_ = pc_client_new();
		// add some event callback.
		pc_add_listener(client_, "onHey", on_hey);
		pc_add_listener(client_, PC_EVENT_DISCONNECT, on_close);

	}

	NetImpl::~NetImpl()
	{

	}

	void NetImpl::on_close( pc_client_t* __client, const char* __events, void* __data )
	{
		printf("client closed: %d.\n", __client->state);
	}

	void NetImpl::on_hey( pc_client_t* __client, const char* __events, void* __data )
	{
		printf("on_hey: %d.\n", __client->state);
	}

	NetImpl* NetImpl::instance()
	{
		if(!inst_)
		{
			inst_ = new NetImpl();
		}
		return inst_;
	}

	bool NetImpl::connect( const char* __host, unsigned short __port )
	{
		struct sockaddr_in __address;

		memset(&__address, 0, sizeof(struct sockaddr_in));
		__address.sin_family = AF_INET;
		__address.sin_port = htons(__port);
		__address.sin_addr.s_addr = inet_addr(__host);

		// try to connect to server.
		if(pc_client_connect(client_, &__address)) {
			printf("fail to connect server.\n");
			pc_client_destroy(client_);
			return false;
		}
		return true;
	}

	void NetImpl::destroy()
	{
		if(inst_)
		{
			delete inst_;
			inst_ = NULL;
		}
	}

	void NetImpl::do_request()
	{
		// compose request
		const char* __route = "connector.entryHandler.hi";
		json_t* __msg = json_object();
		json_t* __str = json_string("hi~");
		json_object_set(__msg, "msg", __str);
		// decref for json object
		json_decref(__str);

		pc_request_t* __request = pc_request_new();
		pc_request(client_, __request, __route, __msg, on_request_cb);

	}

	void NetImpl::on_request_cb( pc_request_t* __req, int __status, json_t* __resp )
	{
		if(__status == -1) {
			printf("Fail to send request to server.\n");
		} else if(__status == 0) {
			char* __json_str = json_dumps(__resp, 0);
			if(__json_str != NULL) {
				printf("server response: %s\n", __json_str);
				free(__json_str);
			}
		}

		// release relative resource with pc_request_t
		json_t*__msg = __req->msg;
		pc_client_t* __client = __req->client;
		json_decref(__msg);
		pc_request_destroy(__req);

		// stop client
		pc_client_stop(__client);

	}

	void NetImpl::do_notify( )
	{
		// compose notify.
		const char* __route = "connector.entryHandler.hello";
		json_t* __msg = json_object();
		json_t* __json_str = json_string("hello");
		json_object_set(__msg, "msg", __json_str);
		// decref json string
		json_decref(__json_str);

		pc_notify_t* __notify = pc_notify_new();
		pc_notify(client_, __notify, __route, __msg, on_notified);

	}

	void NetImpl::on_notified( pc_notify_t* __req, int __status )
	{
		if(__status == -1) {
			printf("Fail to send notify to server.\n");
		} else {
			printf("Notify finished.\n");
		}

		// release resources
		json_t* __msg = __req->msg;
		json_decref(__msg);
		pc_notify_destroy(__req);

	}
}
