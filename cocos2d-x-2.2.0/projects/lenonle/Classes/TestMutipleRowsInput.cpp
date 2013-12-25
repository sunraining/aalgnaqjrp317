//
//  TestMutipleRowsInput.cpp
//  lenonle
//
//  Created by Ken on 13-12-24.
//
//

#include "TestMutipleRowsInput.h"
#define FONT_NAME "Thonburi"
#define FONT_SIZE 32

static CCRect getRect(CCNode * pNode)
{
    CCRect rc;
    rc.origin = pNode->getPosition();
    rc.size = pNode->getContentSize();
    rc.origin.x -= rc.size.width / 2;
    rc.origin.y -= rc.size.height / 2;
    return rc;
}


bool TestMutipleRowsInput::init()
{
	hideKeyboardFlag = keyboardIsHide;
	
    // add CCTextFieldTTF
    CCSize s = CCDirector::sharedDirector()->getWinSize();
	
	CCSprite* bkPic = CCSprite::create("lenonle res/test resources/testInput.png");
	bkPic->setPosition(ccp(s.width / 2, s.height/2 + 50));
	addChild(bkPic,0);
	
	const CCSize* textFieldSize = new CCSize(bkPic->getContentSize().width, bkPic->getContentSize().height);
    CCTextFieldTTF * pTextField = CCTextFieldTTF::textFieldWithPlaceHolder("<click here for input>", *textFieldSize , kCCTextAlignmentLeft,
																		   FONT_NAME,
																		   FONT_SIZE);
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // on android, CCTextFieldTTF cannot auto adjust its position when soft-keyboard pop up
    // so we had to set a higher position to make it visable
    pTextField->setPosition(ccp(s.width / 2, s.height/2 + 50));
#else
    pTextField->setPosition(ccp(s.width / 2, s.height / 2));
#endif
    addChild(pTextField,1);

	
    m_pTrackNode = pTextField;
	this->setTouchEnabled(true);
	
	return true;
}

void TestMutipleRowsInput::registerWithTouchDispatcher()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

bool TestMutipleRowsInput::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	m_beginPos = pTouch->getLocation();
	return true;
}

void TestMutipleRowsInput::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint endPos = pTouch->getLocation();
	CCLog("touch ended");
    float delta = 5.0f;
    if (::abs(endPos.x - m_beginPos.x) > delta
        || ::abs(endPos.y - m_beginPos.y) > delta)
    {
        // not click
        m_beginPos.x = m_beginPos.y = -1;
        return;
    }
	
    CCRect rect;
    CCPoint point = convertTouchToNodeSpaceAR(pTouch);
	
    rect = getRect(m_pTrackNode);
	
	if(hideKeyboardFlag == keyboardIsHide){
		CCLog("attach");
		this->onClickTrackNode(rect.containsPoint(point));
	}else if(hideKeyboardFlag == keyboardIsShow){
		
		CCLog("detach");
		
		CCTextFieldTTF * pTextField = (CCTextFieldTTF*)m_pTrackNode;
		pTextField->detachWithIME();
	}
}

void TestMutipleRowsInput::keyboardWillShow(CCIMEKeyboardNotificationInfo& info)
{
	hideKeyboardFlag = keyboardIsShow;
	
    CCRect rectTracked = getRect(m_pTrackNode);
	
    // if the keyboard area doesn't intersect with the tracking node area, nothing need to do.
    if (! rectTracked.intersectsRect(info.end))
    {
        return;
    }
	
    // assume keyboard at the bottom of screen, calculate the vertical adjustment.
    adjustVert = info.end.getMaxY() - rectTracked.getMinY();
	
    // move all the children node of KeyboardNotificationLayer
    CCArray * children = getChildren();
    CCNode * node = 0;
    int count = children->count();
    CCPoint pos;
    for (int i = 0; i < count; ++i)
    {
        node = (CCNode*)children->objectAtIndex(i);
        pos = node->getPosition();
        pos.y += adjustVert;
        node->setPosition(pos);
    }
}

void TestMutipleRowsInput::keyboardWillHide(CCIMEKeyboardNotificationInfo& info)
{
	hideKeyboardFlag = keyboardIsHide;
    // move back all the children node of KeyboardNotificationLayer
    CCArray * children = getChildren();
    CCNode * node = 0;
    int count = children->count();
    CCPoint pos;
	for (int i = 0; i < count; ++i)
    {
        node = (CCNode*)children->objectAtIndex(i);
        pos = node->getPosition();
        pos.y -= adjustVert;
        node->setPosition(pos);
    }
	
}

void TestMutipleRowsInput::onClickTrackNode(bool bClicked)
{
    CCTextFieldTTF * pTextField = (CCTextFieldTTF*)m_pTrackNode;
    if (bClicked)
    {
        // TextFieldTTFTest be clicked
        pTextField->attachWithIME();
		pTextField->setColor(ccBLUE);
    }
}

