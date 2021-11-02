#include <iostream>
#include <QDebug>

#include <QApplication>
#include <QVBoxLayout>
#include <QJsonObject>

#include "component/ButtonComponent.hpp"
#include "component/NumberSettingComponent.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    
    
    std::cout << "hello world!" << std::endl;
    qDebug() << "hello QT5!";


    QWidget w;
    w.resize(500,400);
    w.show();



    QVBoxLayout layout(&w);

    // SettingComponentAbs* component = new ButtonComponent(12,
    //     { {"displayName" , "状态查询"} }, &w);

    layout.addWidget(new ButtonComponent(123, { {"displayName" , "状态查询"} }, &w));

    SettingComponentAbs* number = new NumberSettingComponent(233,
        { {"minValue", 0} , {"maxValue", 255}, {"displayName" , "视频增益"} }, &w);
    layout.addWidget(number);


    return app.exec();
}