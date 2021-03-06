#include "json_server.h"
namespace chess
{
	JsonServer* JsonServer::server_ = NULL;
	JsonServer* JsonServer::instance( const char* __file_name )
	{
		if(!server_)
		{
			server_ = new JsonServer(__file_name); 
		}
		return server_;
	}

	JsonServer::JsonServer(const char* __file_name):JsonBase(__file_name),port_(0)
	{
		//	get the value of host and port
		 json_t* __json_host = json_object_get(json_load_, "host");
		 json_t* __json_port = json_object_get(json_load_, "port");
<<<<<<< HEAD
		 json_t* __json_url = json_object_get(json_load_, "url");
		 host_ = json_string_value(__json_host);
		 port_ = json_integer_value(__json_port);
		 url_ = json_string_value(__json_url);
=======
		 host_ = json_string_value(__json_host);
		 port_ = json_integer_value(__json_port);
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
	}

	void JsonServer::destroy()
	{
		if(server_)
		{
			delete server_;
			server_ = NULL;
		}
	}

	const char* JsonServer::host() const
	{
		return host_;
	}

	unsigned int JsonServer::port() const
	{
		return port_;
	}

<<<<<<< HEAD
	const char* JsonServer::url() const
	{
		return url_;
	}

=======
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
}