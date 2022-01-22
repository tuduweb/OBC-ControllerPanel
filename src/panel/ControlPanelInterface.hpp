#include "base/ControlInterface.hpp"

#include <QWidget>

class ControlPanelInterface : public QWidget, ControlInterface 
{
public:
    ControlPanelInterface(QWidget* parent = nullptr) : QWidget(parent), ControlInterface(){};

protected:
    virtual bool loadSettings(const QJsonObject& settingsObj) = 0;

};