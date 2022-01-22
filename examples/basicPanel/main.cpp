#include <iostream>
#include <QDebug>

#include <QApplication>
#include <QVBoxLayout>
#include <QJsonObject>

#include "component/ButtonComponent.hpp"
#include "component/NumberSettingComponent.hpp"
#include "component/SwitchSettingComponent.hpp"
#include "component/MultiSelectComponent.hpp"

#include "BasicControlPanel.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::cout << "hello world!" << std::endl;
    qDebug() << "hello QT5!";

    QWidget w;
    w.resize(500, 400);
    w.show();

    QVBoxLayout layout(&w);

    // SettingComponentAbs* component = new ButtonComponent(12,
    //     { {"displayName" , "状态查询"} }, &w);

    layout.addWidget(new ButtonComponent(123, {{"displayName", "状态查询"}}, &w));

    SettingComponentAbs *number = new NumberSettingComponent(233,
                                                             {{"minValue", 0}, {"maxValue", 255}, {"displayName", "视频增益"}}, &w);
    layout.addWidget(number);

    SettingComponentAbs *switchComponent = new SwitchSettingComponent(333,
                                                                      {{"displayName", "电子放大"}}, &w);
    //ui->mainLayout->addWidget(switchComponent);
    layout.addWidget(switchComponent);

    SettingComponentAbs* component = new MultiSelectComponent(444,
        { {"selections", QJsonObject{{"大视场方向", 0}, {"小视场方向", 1}, {"超级方向", 2}}}, {"displayName" , "变焦"} }, &w);
    layout.addWidget(component);

    BasicControlPanel* panel = new BasicControlPanel(&w);
    layout.addWidget(panel);

    return app.exec();
}