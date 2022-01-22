#pragma once

#include <QObject>



class ControlInterface
{

public:
    ControlInterface() {};
    ~ControlInterface() {};

signals:
    void SendEvent(const QJsonObject& obj);
public://slots
    virtual void HandleEvent(const QJsonObject& obj) {};
};