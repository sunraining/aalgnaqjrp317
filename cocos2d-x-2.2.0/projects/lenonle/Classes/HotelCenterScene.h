#ifndef __HotelCenter_SCENE_H__
#define __HotelCenter_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HotelCenter : public cocos2d::CCScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
protected:
    UILayer* m_pUILayer;
    
    void hotelCornerBtnCallBack(CCObject* pSender);          // hotelCornerBtnCallBack
    
    // implement the "static node()" method manually
    CREATE_FUNC(HotelCenter);
};

#endif // __HotelCenter_SCENE_H__
