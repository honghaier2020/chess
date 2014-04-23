/********************************************************************
	created:	2014/04/19
	created:	19:4:2014   18:45
	file base:	json_server
	file ext:	h
	author:		King Lee
	
	purpose:	read config file of server
	*********************************************************************/
#include "json_base.h"
#include <string>

namespace chess
{
	class JsonServer : public JsonBase
	{
	public:
		JsonServer(const char* __file_name);

		static JsonServer* instance(const char* __file_name);

		static void destroy();

		const char* host() const;

		unsigned int port() const;

	private:
		static JsonServer* server_;

		const char* host_;

		unsigned int port_;
	};
}