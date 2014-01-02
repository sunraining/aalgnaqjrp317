#ifndef __Jifenshangc_SCENE_H__
#define __Jifenshangc_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Jifenshangc : public cocos2d::CCScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
protected:
    UILayer* m_pUILayer;
    
    // back callback
    void backBtnCallBack(CCObject* pSender);
    
    // home callback
    void homeBtnCallBack(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Jifenshangc);
};

#endif // __Jifenshangc_SCENE_H__
