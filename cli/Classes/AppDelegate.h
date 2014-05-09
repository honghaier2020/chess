#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"
#include <jansson.h>

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by CCDirector.
*/
class  AppDelegate : private cocos2d::CCApplication
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    /**
    @brief    Implement CCDirector and CCScene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();

	//	other interface
	//	connect server 
	void connect(const char* __host,unsigned short __port);

<<<<<<< HEAD
	void connect(const char* __url);

=======
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
	//	send a message to server,just a test
	void do_request(json_t* __msg);

	//	send a notify to server,just a test also
	void do_notify();
<<<<<<< HEAD

	//	for http
	//	send a post to http server
	void do_post(void* __data);

	//	set user data
	void set_user_data(void* __user_data);
=======
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
};

#endif // _APP_DELEGATE_H_

