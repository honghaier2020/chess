#include "net_http_impl.h"
#include <stdio.h>

namespace chess
{
	NetHttpImpl* NetHttpImpl::inst_ = NULL;
	NetHttpImpl::NetHttpImpl()
	{
		//	reference from : http://curl.haxx.se/libcurl/c/example.html
		curl_ = curl_easy_init();
		if(curl_)
		{
			curl_easy_setopt(curl_, CURLOPT_URL, "http://example.com");
			/* example.com is redirected, so we tell libcurl to follow redirection */ 
			curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);

			/* Perform the request, res will get the return code */ 
			res_ = curl_easy_perform(curl_);
			/* Check for errors */ 
			if(res_ != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res_));

			/* always cleanup */ 
			curl_easy_cleanup(curl_);
		}
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
			delete inst_;
			inst_ = NULL;
		}
	}
}