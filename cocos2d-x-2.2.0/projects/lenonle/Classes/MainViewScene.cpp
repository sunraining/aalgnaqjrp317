#include "MainViewScene.h"

#include "CustomerCenterScene.h"
#include "HotelCenterScene.h"


#include "cocos-ext.h"
USING_NS_CC_EXT;
#pragma coment(lib,"pthreadVCE2.lib");
using namespace std;

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


//定义的写数据的回调函数。 但是在回调函数中只是将获取到的数据输出而已
size_t write_data(void *buffer, size_t size, size_t nmemb, void *stream)
{
    printf("%s",(char*)buffer);
    return size*nmemb;//这里一定要返回实际返回的字节数
}

void MainView::hotelCenterBtnCallBack(CCObject* pSender)
{
    CCHttpRequest* request = new CCHttpRequest();
    request->setUrl("http://www.lenonle.com/app/api.aspx?");
    request->setRequestType(CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, callfuncND_selector(MainView::onGetFinished));
    
    // write the post data
    /*
     登录
     请求参数：recode:接口编码，memberName:登录名，pwd:密码，sign:验证加密字符串
     */
//    const char* postData = "reqcode=32001&memberName=judy&pwd=123456&sign=md5('32001'+%20key)";
    
    /*
     注册
     请求参数：recode:接口编码，memberName:用户名，pwd:密码，email:邮箱，sign:验证加密字符串
     */
//    const char* postData = "reqcode=33001&memberName=sunny&pwd=123456&email=judy11@163.com&sign=md5('33001'+%20key)";
    
    /*
     会议订单列表
     */
    const char* postData = "reqcode=11004&memberid=156&pageSize=10&pageIndex=2&sign=";
    
    request->setRequestData(postData, strlen(postData));
    request->setTag("POST test1");
    CCHttpClient::getInstance()->send(request);
    request->release();
    
    return;
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


#pragma mark -
#pragma mark RequestFinished
void MainView::onGetFinished(CCNode *node,void *data)
{
    CCHttpResponse *response = (CCHttpResponse*)data;
    if (!response)
    {
        return;
    }
    int s=response->getHttpRequest()->getRequestType();
    CCLog("request type %d",s);
    
    
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        CCLog("%s ------>oked", response->getHttpRequest()->getTag());
    }
    
    int statusCode = response->getResponseCode();
    
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLog("%s",statusString);
    
    if (!response->isSucceed())
    {
        CCLog("response failed");
        CCLog("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    std::vector<char> *buffer = response->getResponseData();
    
    int data_length =  buffer->size();
    string resp;
    for (int i = 0;i<data_length;++i)
    {
        resp+=(*buffer)[i];
    }
    CCLog("%s",resp.c_str());
//    parserJson(resp);
    
    
}

