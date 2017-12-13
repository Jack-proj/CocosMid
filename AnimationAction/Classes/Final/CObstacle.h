#ifndef __COBSTACLE_H__
#define __COBSTACLE_H__

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"


class CObstacle {
private:
	cocos2d::Node   *_obsRoot;
	cocos2d::Sprite *_body;
	//cocos2d::Rect _rect2;

	cocos2d::MoveTo *_obsAction;
	cocostudio::timeline::ActionTimeline *_triAction;
public:
	cocos2d::Rect _rect2;
	CObstacle(const char *csbname, cocos2d::Layer &parent);
	~CObstacle();
	void effectPlay();
	void setPosition(const cocos2d::Point &pos);
	void setPosition(const float x, const float y);
	void setScale(float s);
};
#endif
