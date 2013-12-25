//
//  TestMutipleRowsInput.h
//  lenonle
//
//  Created by Ken on 13-12-24.
//
//

#ifndef lenonle_TestMutipleRowsInput_h
#define lenonle_TestMutipleRowsInput_h

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class TestMutipleRowsInput : public CCLayer, public CCIMEDelegate
{
public:
	
	bool init();
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void keyboardWillShow(CCIMEKeyboardNotificationInfo& info);
    virtual void keyboardWillHide(CCIMEKeyboardNotificationInfo& info);
    virtual void registerWithTouchDispatcher();
	void onClickTrackNode(bool bClicked);
	
private:
	float adjustVert;
	int hideKeyboardFlag;
	typedef enum
	{
		keyboardIsShow,
		keyboardIsHide,
	} hideKeyboard;

	//	// CCLayer
//    void onEnter();
//    void onExit();
	
	// static
//    static InputTextField* textFieldWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize);
//    static InputTextField * textFieldWithPlaceHolder(const char *placeholder, const CCSize& dimensions, CCTextAlignment alignment, const char *fontName, float fontSize);
	
	// CCTextFieldDelegate
//    virtual bool onTextFieldAttachWithIME(CCTextFieldTTF *pSender);
//    virtual bool onTextFieldDetachWithIME(CCTextFieldTTF * pSender);
//    virtual bool onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen);
//    virtual bool onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen);

	// get the rect of textField
//    CCRect getRect();
	
//	// is the touch in the text field
//	bool isInTextField(CCTouch *pTouch);
//	
//	//open IME
//	void openIME();
//	
//	//close IME
//	void closeIME();
//	
//	// init cursor
//    void initCursorSprite(int nHeight);

protected:
	
    CCNode * m_pTrackNode;
	CCPoint m_beginPos;
};

#endif
