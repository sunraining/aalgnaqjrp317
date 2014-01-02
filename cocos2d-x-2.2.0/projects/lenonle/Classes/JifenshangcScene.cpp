#include "JifenshangcScene.h"

#include "CustomerCenterScene.h"

using namespace cocos2d::extension;

USING_NS_CC;

// on "init" you need to initialize your instance
bool Jifenshangc::init()
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
    
    
    Layout* equipe_root = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/Jifenshangc_1/Jifenshangc_1.json"));
    
    m_pUILayer->addWidget(equipe_root);
    
    // back btn
    UIButton* back_btn = dynamic_cast<UIButton*>(m_pUILayer->getWidgetByName("back_btn"));
	back_btn->addReleaseEvent(this, coco_releaseselector(Jifenshangc::backBtnCallBack));
    
    // home btn
    UIButton* home_btn = dynamic_cast<UIButton*>(m_pUILayer->getWidgetByName("home_btn"));
	home_btn->addReleaseEvent(this, coco_releaseselector(Jifenshangc::homeBtnCallBack));
    
    
    
    
    this->addChild(m_pUILayer);
    
    
    
    return true;
}

// back callback
void Jifenshangc::backBtnCallBack(CCObject* pSender)
{
    CustomerCenter* pScene = new CustomerCenter;
    pScene->init();
    CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInL::create(0.3, pScene));
}

// home callback
void Jifenshangc::homeBtnCallBack(CCObject* pSender)
{
    CustomerCenter* pScene = new CustomerCenter;
    pScene->init();
    CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInL::create(0.3, pScene));
}

