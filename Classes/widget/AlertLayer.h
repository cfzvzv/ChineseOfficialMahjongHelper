﻿#ifndef _ALERT_LAYER_H_
#define _ALERT_LAYER_H_

#include "cocos2d.h"

class AlertLayer : public cocos2d::Layer {
public:
    bool initWithTitle(const std::string &title, cocos2d::Node *node, const std::function<void ()> &confirmCallback, const std::function<void ()> &cancelCallback);

    static void showWithNode(const std::string &title, cocos2d::Node *node, const std::function<void ()> &confirmCallback, const std::function<void ()> &cancelCallback);
    static void showWithMessage(const std::string &title, const std::string &message, const std::function<void ()> &confirmCallback, const std::function<void ()> &cancelCallback);

private:
    void onCancelButton(cocos2d::Ref *sender);
    void onConfirmButton(cocos2d::Ref *sender);

    std::function<void ()> _confirmCallback;
    std::function<void ()> _cancelCallback;
};

#endif