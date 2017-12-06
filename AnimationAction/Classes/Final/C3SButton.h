#ifndef __C3SBUTTON_H__
#define __C3SBUTTON_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
class C3SButton :public Node
{
private:
	cocos2d::Sprite *_SwitchOffPic;
	cocos2d::Sprite *_SwitchTDPic;
	cocos2d::Sprite *_SwitchOnPic;

	cocos2d::Size  _BtnSize;
	cocos2d::Point _BtnLoc;
	cocos2d::Rect  _BtnRect;

	float _fScale;	// �Ϥ��Y�񪺤j�p
	bool _bTouched;	// �O�_�Q���U
	bool _bSwitchOn;// ���s�O�_�A�}�Ҫ��A
	bool _bVisible; // �O�_���

public:
	C3SButton();
	static C3SButton* create(); // �إߪ��󪺹���
	void setButtonInfo(const char *offImg, const char *onImg, const char *tdImg, const cocos2d::Point locPt);
	bool touchesBegan(cocos2d::Point inPos);
	bool touchesMoved(cocos2d::Point inPos);
	bool touchesEnded(cocos2d::Point inPos);
	void setVisible(bool bVis);
	void setScale(float scale);
	bool getStatus();

};


#endif
