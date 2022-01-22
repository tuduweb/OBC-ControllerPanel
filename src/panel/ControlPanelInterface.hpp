#include "base/ControlInterface.hpp"

#include <QWidget>

class ControlPanelInterface : public ControlInterface 
{
public:
    ControlPanelInterface(QWidget* parent = nullptr) : ControlInterface(parent){};

protected:
    virtual bool loadSettings(const QJsonObject& settingsObj) = 0;

};