#ifndef __MainView_SCENE_H__
#define __MainView_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MainView : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
protected:
    UILayer* m_pUILayer;
    
    // hotel center callback
    void hotelCenterBtnCallBack(CCObject* pSender);
    
    // customer center callback
    void customerCenterBtnCallBack(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainView);
};

#endif // __MainView_SCENE_H__
