#ifndef __PLAY_MENU_SCENE_H__
#define __PLAYMENU_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "Final/C3SButton.h"



class Play_Menu : public cocos2d::Layer
{
private:
	cocos2d::Sequence *_mySequence;
	C3SButton *_playbtn;
	CCLabelTTF *label;
	int counter;  
	char _cSceneNo[1];
	Label *Txttime;

public:
	Label *label1;

	~Play_Menu();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	//void CuberBtnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void doStep(float dt);
	void next(float dt);

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	void PlayBtnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);


 // implement the "static create()" method manually
	CREATE_FUNC(Play_Menu);
};
#endif // __HELLOWORLD_SCENE_H__
