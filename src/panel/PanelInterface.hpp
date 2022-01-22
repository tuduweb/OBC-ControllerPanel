#pragma once

#include <QWidget>

#include "utils/OBCHelpers.hpp"

#include "../component/ButtonComponent.hpp"
#include "../component/NumberSettingComponent.hpp"
#include "../component/SwitchSettingComponent.hpp"
#include "../component/MultiSelectComponent.hpp"

namespace OBC::Panel{
    class PanelInterface {
    
    protected:
        virtual bool loadSettings(const QJsonObject& settingsObj) = 0;
    };
};