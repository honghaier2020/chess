/********************************************************************
	created:	2014/04/13
	created:	13:4:2014   14:06
	file base:	net_impl
	file ext:	h
	author:		King Lee
	
	purpose:	implement a net interface to communicate with server. it a simple wrapped for libpomelo.
*********************************************************************/
#ifndef net_impl_h__
#define net_impl_h__
#include "pomelo.h"

namespace chess{

	class NetImpl{
	public:
		NetImpl();

		~NetImpl();

		//	get a net impl instance
		static NetImpl* instance();

		//	destroy instance
		static void destroy();

		//	connect to server
		bool connect(const char* __host, unsigned short __port);

		//	do a request to server
		void do_request(json_t* __msg);

		// send a notify
		void do_notify();

		//	test code
		void do_request_test();

	public:
		//	callback function
		static void on_hey(pc_client_t* __client, const char* __events, void* __data);
		
		//	event callback, it will be fired when trigger the event.
		static void on_close(pc_client_t* __client, const char* __events, void* __data);

		//	request callback
		static void on_request_cb(pc_request_t* __req, int __status, json_t* __resp);

		//	notify callback 
		static void on_notified(pc_notify_t* __req, int __status);
	private:
		//	pomelo client instance
		pc_client_t* client_;

		//	singleton instance
		static NetImpl* inst_;

		//	disable copy construction and copy assignment
		NetImpl(const NetImpl&);
		NetImpl& operator = (const NetImpl&);
	};
}

#endif // net_impl_h__
