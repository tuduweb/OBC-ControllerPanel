#include <iostream>
#include <QDebug>

#include <QApplication>
#include <QVBoxLayout>
#include <QJsonObject>

#include "component/ButtonComponent.hpp"
#include "component/NumberSettingComponent.hpp"

#include "XtermSettingsWidget.hpp"

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

    layout.addWidget(new XtermSettingsWidget(&w));

    return app.exec();
}