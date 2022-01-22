#include "BasicControlPanel.hpp"

#include "qdebug.h"

#include <QVBoxLayout>

//components
#include "component/ButtonComponent.hpp"
#include "component/NumberSettingComponent.hpp"
#include "component/SwitchSettingComponent.hpp"
#include "component/MultiSelectComponent.hpp"


BasicControlPanel::BasicControlPanel(QWidget* parent) : ControlPanelInterface(parent)
{
    resize(500, 400);

    qDebug() << "hello panel";

    QVBoxLayout* layout = new QVBoxLayout();
    setLayout(layout);

    layout->addWidget(new ButtonComponent(123, {{"displayName", "状态查询"}}, this));

    SettingComponentAbs *number = new NumberSettingComponent(233,
                                                             {{"minValue", 0}, {"maxValue", 255}, {"displayName", "视频增益"}}, this);
    layout->addWidget(number);

    SettingComponentAbs *switchComponent = new SwitchSettingComponent(333,
                                                                      {{"displayName", "电子放大"}}, this);
    //ui->mainLayout->addWidget(switchComponent);
    layout->addWidget(switchComponent);

    SettingComponentAbs* component = new MultiSelectComponent(444,
        { {"selections", QJsonObject{{"大视场方向", 0}, {"小视场方向", 1}, {"超级方向", 2}}}, {"displayName" , "变焦"} }, this);
    layout->addWidget(component);

    this->show();

}