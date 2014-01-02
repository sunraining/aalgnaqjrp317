#include "CustomerCenterScene.h"

#include "JifenshangcScene.h"

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
    
    // 积分商城 btn
	UIButton* jifenshangc_btn = dynamic_cast<UIButton*>(m_pUILayer->getWidgetByName("pointsmall_btn"));
	jifenshangc_btn->addReleaseEvent(this, coco_releaseselector(CustomerCenter::jifenshangcBtnCallBack));
    
    
    this->addChild(m_pUILayer);
    
    
    
    return true;
}

// hotel center callback
void CustomerCenter::hotelCenterBtnCallBack(CCObject* pSender)
{
    
}

// jifenshangcheng callback
void CustomerCenter::jifenshangcBtnCallBack(CCObject* pSender)
{
    Jifenshangc* pScene = new Jifenshangc;
    pScene->init();
    CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInR::create(0.3, pScene));
}

