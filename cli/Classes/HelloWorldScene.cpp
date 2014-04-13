#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "CocosGUI.h"
#include "UIWidget.h"
#include "SceneReader.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

	if(1)
	{
	//	use cocos stdio ui editor 
/*
	before the version 2.1.5a, maybe it looks like:
	CCNode *pNode = CCJsonReader::sharedJsonReader()->createNodeWithJsonFile("NewProject_1.json"); 
	this->addChild(pNode); 

	cocos2dx 2.1.5a Update:
	1. CCJsonReader modify to CCSSceneReader. B+EGmQTN  
	2. CCJsonReader ::sharedSceneReader modify to CCSSceneReader::sharedSceneReader(). 
	3. CCJsonReader::purgeJsonReader modify to CCSSceneReader::purgeSceneReader. 
	4. CCJsonReader::createNodeWithJsonFile modify to CCSSceneReader::createNodeWithSceneFile. 
*/
		CCNode *pNode = cocos2d::extension::SceneReader::sharedSceneReader()->createNodeWithSceneFile("ui\\NewProject_1.json"); 
		this->addChild(pNode); 
	}
	else{
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

		/////////////////////////////
		// 2. add a menu item with "X" image, which is clicked to quit the program
		//    you may modify it.

		// add a "close" icon to exit the progress. it's an autorelease object
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(HelloWorld::menuCloseCallback));

		pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
			origin.y + pCloseItem->getContentSize().height/2));

		// create menu, it's an autorelease object
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		this->addChild(pMenu, 1);

		/////////////////////////////
		// 3. add your codes below...

		// add a label shows "Hello World"
		// create and initialize a label

		CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);

		// position the label on the center of the screen
		pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
			origin.y + visibleSize.height - pLabel->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(pLabel, 1);

		// add "HelloWorld" splash screen"
		CCSprite* pSprite = CCSprite::create("HelloWorld.png");

		// position the sprite on the center of the screen
		pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(pSprite, 0);
	}
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
