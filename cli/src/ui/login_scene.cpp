#include "../ui/login_scene.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

namespace chess
{

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
		ui_layer_->scheduleUpdate();
		addChild(ui_layer_);

		// register root from json

		layout_ = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("ui/DemoLogin/DemoLogin.ExportJson"));

		ui_layer_->addWidget(layout_);

		TextField* comfirm_textfield = static_cast<TextField*>(ui_layer_->getWidgetByName("confirm_TextField"));
		comfirm_textfield->addEventListenerTextField(this, textfieldeventselector(LoginScene::text_field_event));

		// close button
		Button* close_button = static_cast<Button*>(ui_layer_->getWidgetByName("close_Button"));
		close_button->addTouchEventListener(this, toucheventselector(LoginScene::menu_close_callback));

		Button* login_button = static_cast<Button*>(ui_layer_->getWidgetByName("login_LabelBMFont"));
		login_button->addTouchEventListener(this, toucheventselector(LoginScene::menu_close_callback));
	}

	void LoginScene::onExit()
	{
		ui_layer_->removeFromParent();
		SceneReader::sharedSceneReader()->purge();
		GUIReader::shareReader()->purge();
		cocos2d::extension::ActionManager::shareManager()->purge();

		CCScene::onExit();
	}

	void LoginScene::menu_close_callback( cocos2d::CCObject* __Sender, cocos2d::ui::TouchEventType __type )
	{
		if (__type == TOUCH_EVENT_ENDED)
		{
			CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			exit(0);
#endif
		}
	}

	void LoginScene::text_field_event( cocos2d::CCObject* __Sender, cocos2d::ui::TextFiledEventType __type )
	{
		switch (__type)
		{
		case TEXTFIELD_EVENT_ATTACH_WITH_IME:
			{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
				TextField* __text_field = dynamic_cast<TextField*>(__Sender);

				if (strcmp(__text_field->getName(), "confirm_TextField") == 0)
				{
					CCMoveBy* __move_by = CCMoveBy::create(0.1f, ccp(0, __text_field->getContentSize().height * 2.5));
					layout_->runAction(__move_by);
				}
#elseif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
				TextField* __text_field = dynamic_cast<TextField*>(__Sender);

				if (strcmp(__text_field->getName(), "confirm_TextField") == 0)
				{
					CCMoveBy* __move_by = CCMoveBy::create(0.1f, ccp(0, __text_field->getContentSize().height * 2.5));
					layout_->runAction(__move_by);
				}

#endif
			}
			break;

		case TEXTFIELD_EVENT_DETACH_WITH_IME:
			{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
				TextField* __text_field = dynamic_cast<TextField*>(__Sender);

				if (strcmp(__text_field->getName(), "confirm_TextField") == 0)
				{
					CCMoveBy* __move_by = CCMoveBy::create(0.1f, ccp(0, -__text_field->getContentSize().height * 2.5));
					layout_->runAction(__move_by);
				}
#endif
			}
			break;

		default:
			break;
		}
	}
}