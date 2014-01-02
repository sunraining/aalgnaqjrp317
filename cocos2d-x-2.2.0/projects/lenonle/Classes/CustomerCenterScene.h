#ifndef __CustomerCenter_SCENE_H__
#define __CustomerCenter_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CustomerCenter : public cocos2d::CCScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
protected:
    UILayer* m_pUILayer;
    
    // hotel center callback
    void hotelCenterBtnCallBack(CCObject* pSender);
    
    // jifenshangcheng callback
    void jifenshangcBtnCallBack(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(CustomerCenter);
};

#endif // __CustomerCenter_SCENE_H__
