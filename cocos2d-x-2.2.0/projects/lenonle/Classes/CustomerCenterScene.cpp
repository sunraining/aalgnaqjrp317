#include "CustomerCenterScene.h"
#include "CocosGUI.h"

using namespace cocos2d::extension;

USING_NS_CC;

// on "init" you need to initialize your instance
bool CustomerCenter::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCScene::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    m_pUILayer = UILayer::create();
    
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
