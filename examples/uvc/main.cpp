#include <iostream>
#include <QDebug>

#include <QApplication>
#include <QVBoxLayout>
#include <QJsonObject>

#include "component/ButtonComponent.hpp"
#include "component/NumberSettingComponent.hpp"

#include "panel/UVCControllPanel.hpp"

using namespace OBC::Panel::ControlPanel;

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

    QJsonObject methodsObj;
    
    QJsonArray items;
    for(int i = 0; i < 5; ++i) {
        QJsonArray _item{1,2,3,4,5};
        items.append(_item);
    }
    methodsObj.insert("control", items);

    UVCControlPanel* panel = new UVCControlPanel(&w);

    layout.addWidget(panel);

    panel->loadSettings(methodsObj);

    panel->ReloadGui();


    return app.exec();
}