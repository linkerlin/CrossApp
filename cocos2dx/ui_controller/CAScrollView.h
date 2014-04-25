//
//  CAScrollView.h
//  cocos2dx
//
//  Created by 栗元峰 on 14-4-23.
//  Copyright (c) 2014年 厦门雅基软件有限公司. All rights reserved.
//

#ifndef __cocos2dx__CAScrollView__
#define __cocos2dx__CAScrollView__

#include <iostream>
#include "sprite_nodes/CCView.h"
#include <deque>

NS_CC_BEGIN

class CAScrollView;
class CAScrollViewDelegate
{
public:

    virtual void scrollViewDidScroll(CAScrollView* view) = 0;
    
    virtual void scrollViewWillBeginDragging(CAScrollView* view) = 0;
    
    virtual void scrollViewDidEndDragging(CAScrollView* view) = 0;
    
    virtual void scrollViewDidZoom(CAScrollView* view) = 0;
    
    void removeDelegate(CAScrollView* view);
};

class CAIndicator;
class CAScrollView: public CAView
{
    
public:

    CAScrollView();
    
    virtual ~CAScrollView();
 
    virtual void onEnterTransitionDidFinish();
    
    virtual void onExitTransitionDidStart();
    
    virtual bool initWithFrame(const cocos2d::CCRect &rect);
    
    void addChild(CCNode * child);

    void addChild(CCNode * child, int zOrder);

    void addChild(CCNode* child, int zOrder, int tag);
    
protected:
    
    CCPoint& getScrollWindowNotOutPoint(CCPoint& point);
    
    float getScrollWindowNotOutHorizontal(float x);
    
    float getScrollWindowNotOutVertical(float y);
    
    void update(float fDelta);
    
    void deaccelerateScrolling(float delay);
    
protected:
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
protected:
    
    CC_SYNTHESIZE(CAScrollViewDelegate*, m_pScrollViewDelegate, ScrollViewDelegate);
    
    CC_PROPERTY_IS(bool, m_bBounces, Bounces);
    
    CC_SYNTHESIZE_IS(bool, m_bBounceHorizontal, BounceHorizontal);
    
    CC_SYNTHESIZE_IS(bool, m_bBounceVertical, BounceVertical);
    
    CC_SYNTHESIZE_IS(bool, m_bscrollEnabled, ScrollEnabled);
    
    CC_SYNTHESIZE_IS(bool, m_bTracking, Tracking);
    
    CC_SYNTHESIZE_IS(bool, m_bDecelerating, Decelerating);
    
    CC_SYNTHESIZE(bool, m_bShowsHorizontalScrollIndicator, ShowsHorizontalScrollIndicator);
    
    CC_SYNTHESIZE(bool, m_bShowsVerticalScrollIndicator, ShowsVerticalScrollIndicator);
    
    CC_SYNTHESIZE(bool, m_bBouncesZoom, BouncesZoom);
    
    CC_SYNTHESIZE_IS_READONLY(bool, m_bZooming, Zooming);
    
    CC_SYNTHESIZE(float, m_fMinimumZoomScale, MinimumZoomScale);
    
    CC_SYNTHESIZE(float, m_fMaximumZoomScale, MaximumZoomScale);
    
    CC_SYNTHESIZE(float, m_fZoomScale, ZoomScale);
    
    CC_PROPERTY(CCSize, m_obContainerSize, ContainerSize);
    
protected:
    
    CAView* m_pContainer;
    
    CAIndicator* m_pIndicatorHorizontal;
    
    CAIndicator* m_pIndicatorVertical;
    
    CCArray* m_pTouches;
    
    float m_fTouchLength;

    CCPoint m_tInertia;
    
    std::deque<CCPoint> m_tPointOffset;
    
};


class CAIndicator: public CCNodeRGBA
{
public:
    
    typedef enum
    {
        CAIndicatorTypeHorizontal,
        CAIndicatorTypeVertical
    }CAIndicatorType;
    
    
public:
    
    CAIndicator();
    
    virtual ~CAIndicator();
    
    static CAIndicator* createWithFrame(const CCRect& rect, CAIndicatorType type);
    
    virtual bool initWithFrame(const CCRect& rect, CAIndicatorType type);
    
    void setIndicator(const CCSize& parentSize, const CCRect& childrenFrame);
    
    void setOpacity(GLubyte opacity);
    
private:

    CCNode* m_pIndicator;
    
    CAIndicatorType m_eType;
};

NS_CC_END
#endif /* defined(__cocos2dx__CAScrollView__) */
