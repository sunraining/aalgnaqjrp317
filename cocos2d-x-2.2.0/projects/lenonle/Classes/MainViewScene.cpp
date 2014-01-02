#include "MainViewScene.h"

#include "CustomerCenterScene.h"
#include "HotelCenterScene.h"

using namespace cocos2d::extension;

USING_NS_CC;

// on "init" you need to initialize your instance
bool MainView::init()
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
    
    Layout* equipe_root = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/mainView/mainView.json"));
    
    m_pUILayer->addWidget(equipe_root);
    
    // hotel center btn
	UIButton* hotel_btn = dynamic_cast<UIButton*>(m_pUILayer->getWidgetByName("hotel_btn"));
	hotel_btn->addReleaseEvent(this, coco_releaseselector(MainView::hotelCenterBtnCallBack));
    
    // customer center btn
	UIButton* customer_btn = dynamic_cast<UIButton*>(m_pUILayer->getWidgetByName("customer_btn"));
	customer_btn->addReleaseEvent(this, coco_releaseselector(MainView::customerCenterBtnCallBack));
    
    
    this->addChild(m_pUILayer);
    
    
    return true;
}


void MainView::hotelCenterBtnCallBack(CCObject* pSender)
{
    HotelCenter* pScene = new HotelCenter();
	pScene->init();
    CCDirector::sharedDirector()->replaceScene(pScene);
}

void MainView::customerCenterBtnCallBack(CCObject* pSender)
{
    CustomerCenter* pScene = new CustomerCenter();
	pScene->init();
    CCDirector::sharedDirector()->replaceScene(pScene);
}
