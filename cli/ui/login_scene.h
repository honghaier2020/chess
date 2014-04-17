/********************************************************************
	created:	2014/04/17
	created:	17:4:2014   7:02
	file base:	login_scene
	file ext:	h
	author:		Lee
	
	purpose:	cocos gui test for login
*********************************************************************/
#ifndef login_scene_h__
#define login_scene_h__

#include "cocos2d.h"
#include "cocos-ext.h"

namespace chess{
	class LoginScene : public cocos2d::CCScene
	{
	public:
		LoginScene();

		~LoginScene();

		virtual void onEnter();

		virtual void onExit();

	private:
		cocos2d::ui::TouchGroup*	ui_layer_;
		cocos2d::ui::Layout*		layout_;
	};
}

#endif // login_scene_h__