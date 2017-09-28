﻿#ifndef _CW_EDIT_BOX_DELETATE_H_
#define _CW_EDIT_BOX_DELETATE_H_

#include <type_traits>
#include <utility>
#include "ui/UIEditBox/UIEditBox.h"

namespace cw {
    class EditBoxReturnDelegate : public cocos2d::ui::EditBoxDelegate {
    public:
        typedef std::function<void (cocos2d::ui::EditBox *editBox)> ccEditBoxReturnCallback;

        template <class _Callable>
        EditBoxReturnDelegate(_Callable &&callback) : _callback(std::forward<_Callable>(callback)) {
            static_assert(std::is_constructible<ccEditBoxReturnCallback, _Callable>::value, "");
        }

        virtual ~EditBoxReturnDelegate() { CCLOG("%s", __FUNCTION__); }

    private:
        EditBoxReturnDelegate(const EditBoxReturnDelegate &other) = delete;
        EditBoxReturnDelegate(EditBoxReturnDelegate &&other) = delete;
        EditBoxReturnDelegate &operator=(const EditBoxReturnDelegate &other) = delete;
        EditBoxReturnDelegate &operator=(EditBoxReturnDelegate &&other) = delete;

        virtual void editBoxReturn(cocos2d::ui::EditBox *editBox) override {
            _callback(editBox);
        }

        ccEditBoxReturnCallback _callback;
    };



    class EditBoxEndWithActionDelegate : public cocos2d::ui::EditBoxDelegate {
    public:
        typedef std::function<void (cocos2d::ui::EditBox *, cocos2d::ui::EditBoxDelegate::EditBoxEndAction)> ccEditBoxEndWithActionCallback;

        template <class _Callable>
        EditBoxEndWithActionDelegate(_Callable &&callback) : _callback(std::forward<_Callable>(callback)) {
            static_assert(std::is_constructible<ccEditBoxEndWithActionCallback, _Callable>::value, "");
        }

        virtual ~EditBoxEndWithActionDelegate() { CCLOG("%s", __FUNCTION__); };

    private:
        EditBoxEndWithActionDelegate(const EditBoxEndWithActionDelegate &other) = delete;
        EditBoxEndWithActionDelegate(EditBoxEndWithActionDelegate &&other) = delete;
        EditBoxEndWithActionDelegate &operator=(const EditBoxEndWithActionDelegate &other) = delete;
        EditBoxEndWithActionDelegate &operator=(EditBoxEndWithActionDelegate &&other) = delete;

        virtual void editBoxReturn(cocos2d::ui::EditBox *) { }
        virtual void editBoxEditingDidEndWithAction(cocos2d::ui::EditBox *editBox, cocos2d::ui::EditBoxDelegate::EditBoxEndAction action) {
            _callback(editBox, action);
        };

        ccEditBoxEndWithActionCallback _callback;
    };
}

#endif