#pragma once
#include "panel/ControlPanelInterface.hpp"

class BasicControlPanel : public ControlPanelInterface
{
    Q_OBJECT
public:
    BasicControlPanel(QWidget* parent = nullptr); // : ControlPanelInterface(parent)

    bool loadSettings(const QJsonObject& settingsObj) { return false; };
public slots:
    void HandleEvent(const QJsonObject& obj);
    void OnComponentLogAvailable(const QString& log);
    void OnComponentValueChanged(int id, int value);

};