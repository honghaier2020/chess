/********************************************************************
	created:	2014/04/23
	created:	23:4:2014   19:48
	file base:	net_http_impl
	file ext:	h
	author:		King Lee
	
	purpose:	a class to encapsulation all http operator.
	node js code look this:

	var http = require('http'); 
	http.createServer(function(req, res) { 
		var post = '';
		req.on('data',function(chuck)
		{
			post += chuck;
			console.log(post);
		});
		res.writeHead(200, {'Content-Type': 'text/html'}); 
		res.write('<h1>hi,</h1>'); 
		res.end('<p>I have get data. many thanks</p>'); 
	}).listen(3000); 
	console.log("HTTP server is listening at port 3000."); 
	
*********************************************************************/
#ifndef net_http_impl_h__
#define net_http_impl_h__

#include "curl.h"

namespace chess{

	class NetHttpImpl
	{
	public:
		NetHttpImpl();

		~NetHttpImpl();

		//	get a net impl instance
		static NetHttpImpl* instance();

		//	destroy instance
		static void destroy();

		//	connect to server use http
		bool connect(const char* __url);

		//	post data to http server
		void post(void* __data);

		void write_data(void* __user_data);

		void clearup();

	public:
		static size_t fun_write_data(void* __buffer, size_t __size, size_t __nmemb, void* __userp);

	private:
		void _check_error();

		static NetHttpImpl* inst_;

		CURL*				curl_;
		CURLcode			res_;
	};
}
#endif // net_http_impl_h__
