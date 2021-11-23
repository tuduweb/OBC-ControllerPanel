#pragma once

#include "component/ButtonComponent.hpp"
#include "component/NumberSettingComponent.hpp"
#include "component/SwitchSettingComponent.hpp"

#include "utils/OBCHelpers.hpp"

#include <QWidget>

class XtermSettingsWidget : public QWidget
{
    public:
        XtermSettingsWidget(QWidget* parent = nullptr);
        ~XtermSettingsWidget() = default;
};