/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "AppDelegate.h"

#include <vector>
#include <string>

#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "../src/net/net_impl.h"
#include "../src/net/net_http_impl.h"
#include "../src/ui/login_scene.h"
#include "../src/json/json_server.h"
#include "../src/util/msg.h"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
	chess::NetImpl::destroy();
	chess::NetHttpImpl::destroy();
	chess::JsonServer::destroy();
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);
	CCSize frameSize = pEGLView->getFrameSize();
	// Set the design resolution
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);
#else
	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
#endif

	vector<string> searchPath;

	// In this demo, we select resource according to the frame's height.
	// If the resource size is different from design resolution size, you need to set contentScaleFactor.
	// We use the ratio of resource's height to the height of design resolution,
	// this can make sure that the resource's height could fit for the height of design resolution.

	// if the frame's height is larger than the height of medium resource size, select large resource.
	if (frameSize.height > mediumResource.size.height)
	{
		searchPath.push_back(largeResource.directory);

		pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
	// if the frame's height is larger than the height of small resource size, select medium resource.
	else if (frameSize.height > smallResource.size.height)
	{
		searchPath.push_back(mediumResource.directory);

		pDirector->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
	}
	// if the frame's height is smaller than the height of medium resource size, select small resource.
	else
	{
		searchPath.push_back(smallResource.directory);

		pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
	}

	// set searching path
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

	// turn on display FPS
	pDirector->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);
	/*
	// create a scene. it's an autorelease object
	CCScene *pScene = HelloWorld::scene();
	*/
	CCScene* __scene = new chess::LoginScene();
	__scene->autorelease();
	// run
	pDirector->runWithScene(__scene);
	//	connect to server and do something
	chess::JsonServer* __json_server = chess::JsonServer::instance("./config/server.json");
	if(__json_server)
	{
		this->connect(__json_server->host(),__json_server->port());
		this->connect(__json_server->url());
	}
	
	if(0){
		this->do_notify();
	}
	else{
		if(0)
		{
			json_t* __msg = json_object();
			json_t* __msg_id = json_integer(MSG_ID::MSG_LOGIN);
			json_object_set(__msg, "msg_id", __msg_id);
			// decref for json object
			json_decref(__msg_id);
			this->do_request(__msg);
		}
		else
		{
			//	post data to http server
			int __val = 9999;
			this->set_user_data(&__val);
			this->do_post("hi, I will post some data, are you ready!");
		}
	}

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	CCDirector::sharedDirector()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	CCDirector::sharedDirector()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AppDelegate::connect( const char* __host,unsigned short __port )
{
	chess::NetImpl::instance()->connect(__host,__port);
	
}

void AppDelegate::connect( const char* __url )
{
	chess::NetHttpImpl::instance()->connect(__url);
}

void AppDelegate::do_request(json_t* __msg)
{
	chess::NetImpl::instance()->do_request(__msg);
}

void AppDelegate::do_notify()
{
	chess::NetImpl::instance()->do_notify();
}

void AppDelegate::do_post(void* __data)
{
	chess::NetHttpImpl::instance()->post(__data);
}

void AppDelegate::set_user_data( void* __user_data )
{
	chess::NetHttpImpl::instance()->write_data(__user_data);
}
