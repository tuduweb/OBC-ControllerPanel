#pragma once
#include <QObject>
#include <QJsonObject>

#include "qdebug.h"

/**
 * 模拟定义设备
 * 测试基础的设备类 比如TCP/Serial这些 其他USB的设备就没法Mock了
 */


//ControlStream DataStream
class MockDevice : public QObject
{
    Q_OBJECT

public:
    MockDevice();

signals:
    void SendEvent(const QJsonObject& obj);

public slots:
    void HandleEvent(const QJsonObject& obj);

    
};