#include "CustomerCenterScene.h"
#include "CocosGUI.h"

using namespace cocos2d::extension;

USING_NS_CC;

CCScene* CustomerCenter::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    CustomerCenter *layer = CustomerCenter::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CustomerCenter::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    /*
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
     
     CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
     
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
     this->addChild(pSprite, 0);*/
    
    m_pUILayer = UILayer::create();
    //    m_pUILayer->scheduleUpdate();
    
    //********************加载场景资源******************//
    
    Layout* equipe_root = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/customerCenter_1/customerCenter_1.json"));
    
    m_pUILayer->addWidget(equipe_root);
    
//	UIButton* hotel_btna = dynamic_cast<UIButton*>(m_pUILayer->getWidgetByName("hotel_btn"));
//	hotel_btna->addReleaseEvent(this, coco_releaseselector(HelloWorld::hotelCornerBtnCallBack));
    
    
    this->addChild(m_pUILayer);
    
    
    
    return true;
}

void CustomerCenter::hotelCenterBtnCallBack(CCObject* pSender)
{
    
}
