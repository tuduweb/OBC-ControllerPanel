#include "MockDevice.hpp"

#include "qjsonarray.h";

MockDevice::MockDevice()
{
    qDebug() << "hello device";
}

void MockDevice::HandleEvent(const QJsonObject& obj)
{
    if(obj.contains("type") == false)
        return;
    
    //mock status
    if(obj["type"] == 123) {
        
        QJsonObject statusObj;
        statusObj.insert("type", "stat");
        QJsonArray items;
        items.push_back(QJsonArray{{"123", "234"}});
        statusObj.insert("data", items);
        
        emit SendEvent(statusObj);
    }
}