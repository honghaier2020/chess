/********************************************************************
	created:	2014/04/23
	created:	23:4:2014   19:48
	file base:	net_http_impl
	file ext:	h
	author:		King Lee
	
	purpose:	a class to encapsulation all http operator.
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

	private:
		static NetHttpImpl* inst_;

		CURL*				curl_;
		CURLcode			res_;
	};
}
#endif // net_http_impl_h__
