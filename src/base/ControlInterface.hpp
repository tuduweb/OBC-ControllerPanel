#pragma once

#include <QWidget>



class ControlInterface : public QWidget
{
    Q_OBJECT

public:
    ControlInterface(QWidget* parent) : QWidget(parent) {};
    ~ControlInterface() {};

signals:
    void SendEvent(const QJsonObject& obj);
public://slots
    virtual void HandleEvent(const QJsonObject& obj) {};
};