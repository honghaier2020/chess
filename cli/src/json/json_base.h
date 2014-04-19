/********************************************************************
	created:	2014/04/19
	created:	19:4:2014   12:22
	file base:	json_base
	file ext:	h
	author:		King Lee
	
	purpose:	a base class to read json files
*********************************************************************/
#include <jansson.h>
namespace chess {
	class JsonBase
	{
	public:
		JsonBase(const char* __file_name)
		{
			json_error_t* __json_error = NULL;
			json_load_ = json_load_file(__file_name,JSON_REJECT_DUPLICATES,__json_error);
		}

		virtual ~JsonBase() {}
	protected:
		json_t* json_load_;
	};
}

