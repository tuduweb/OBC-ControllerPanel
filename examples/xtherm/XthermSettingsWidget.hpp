#pragma once

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "component/ButtonComponent.hpp"
#include "component/NumberSettingComponent.hpp"
#include "component/SwitchSettingComponent.hpp"

#include "utils/OBCHelpers.hpp"

#include <QWidget>

class XthermSettingsWidget : public QWidget
{
    public:
        XthermSettingsWidget(QWidget* parent = nullptr);
        ~XthermSettingsWidget() = default;
};