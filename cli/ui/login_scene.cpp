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
		layout_ = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("cocosgui/gui_examples/DemoLogin/DemoLogin.json"));
		ui_layer_->addWidget(layout_);
	}

	void LoginScene::onExit()
	{
		ui_layer_->removeFromParent();
		SceneReader::sharedSceneReader()->purge();
		GUIReader::shareReader()->purge();
		cocos2d::extension::ActionManager::shareManager()->purge();

		CCScene::onExit();
	}
}