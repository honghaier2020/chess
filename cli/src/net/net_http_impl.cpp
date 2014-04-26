#include "net_http_impl.h"
#include <stdio.h>

namespace chess
{
	NetHttpImpl* NetHttpImpl::inst_ = NULL;
	NetHttpImpl::NetHttpImpl()
	{
		//	reference from : http://curl.haxx.se/libcurl/c/example.html
		curl_ = curl_easy_init();
	}

	NetHttpImpl::~NetHttpImpl()
	{

	}

	NetHttpImpl* NetHttpImpl::instance()
	{
		if(!inst_)
		{
			inst_ = new NetHttpImpl();
		}
		return inst_;
	}

	void NetHttpImpl::destroy()
	{
		if(inst_)
		{
			inst_->clearup();
			delete inst_;
			inst_ = NULL;
		}
	}

	bool NetHttpImpl::connect( const char* __url )
	{
		if(curl_)
		{
			curl_easy_setopt(curl_, CURLOPT_URL, __url);

			curl_easy_setopt( curl_, CURLOPT_WRITEFUNCTION, fun_write_data );
		}
		return true;
	}

	size_t NetHttpImpl::fun_write_data( void* __buffer, size_t __size, size_t __nmemb, void* __userp )
	{
		int* __val = static_cast<int*>(__userp);
		char __data[512] = {};
		strcpy(__data,(const char*)__buffer);
		return __size;
	}

	void NetHttpImpl::_check_error()
	{
		/* Check for errors */ 
		if(res_ != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res_));
		}
	}

	void NetHttpImpl::write_data(void* __user_data)
	{
		curl_easy_setopt( curl_, CURLOPT_WRITEDATA, __user_data );
	}

	void NetHttpImpl::clearup()
	{
		/* always cleanup */ 
		curl_easy_cleanup(curl_);
	}

	void NetHttpImpl::post( void* __data )
	{
		/* Now specify the POST data */
		curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, __data);
		/* Perform the request, res will get the return code */ 
		res_ = curl_easy_perform(curl_);
		_check_error();
	}
}