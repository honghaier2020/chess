#include "../ui/login_scene.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

namespace chess
{
	void LoginScene::menuCloseCallback( cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type )
	{

	}

	void LoginScene::textFieldEvent( cocos2d::CCObject* pSender, cocos2d::ui::TextFiledEventType type )
	{

	}


	LoginScene::LoginScene():ui_layer_(NULL),layout_(NULL)
	{
		CCScene::init();
	}

	LoginScene::~LoginScene()
	{

	}

	void LoginScene::onEnter()
	{
		CCScene::onEnter();
		ui_layer_ = TouchGroup::create();
		layout_->scheduleUpdate();
		addChild(ui_layer_);

		// register root from json
		layout_ = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("cocosgui/gui_examples/DemoLogin/DemoLogin.json"));
		ui_layer_->addWidget(layout_);
	}

	void LoginScene::onExit()
	{

	}
		
}