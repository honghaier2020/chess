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

<<<<<<< HEAD
		const char* url() const;

=======
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
	private:
		static JsonServer* server_;

		const char* host_;

<<<<<<< HEAD
		const char* url_;

=======
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
		unsigned int port_;
	};
}