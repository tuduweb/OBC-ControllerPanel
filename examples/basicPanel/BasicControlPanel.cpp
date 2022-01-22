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

    QVector<SettingComponentAbs*> compontents;

    //compontent::maker()

    compontents.append(new ButtonComponent(123, {{"displayName", "状态查询"}}, this));
    layout->addWidget(compontents.last());

    //SettingComponentAbs *number = new NumberSettingComponent(233, {{"minValue", 0}, {"maxValue", 255}, {"displayName", "视频增益"}}, this);
    compontents.append(new NumberSettingComponent(233, {{"minValue", 0}, {"maxValue", 255}, {"displayName", "视频增益"}}, this));
    layout->addWidget(compontents.last());

    for(const auto& item : compontents) {
        connect(item, &SettingComponentAbs::OnLogAvailable, this, &BasicControlPanel::OnComponentLogAvailable, Qt::DirectConnection);
        connect(item, &SettingComponentAbs::ValueChanged, this, )
    }

    // SettingComponentAbs *switchComponent = new SwitchSettingComponent(333,
    //                                                                   {{"displayName", "电子放大"}}, this);
    // //ui->mainLayout->addWidget(switchComponent);
    // layout->addWidget(switchComponent);

    // SettingComponentAbs* component = new MultiSelectComponent(444,
    //     { {"selections", QJsonObject{{"大视场方向", 0}, {"小视场方向", 1}, {"超级方向", 2}}}, {"displayName" , "变焦"} }, this);
    // layout->addWidget(component);

    this->show();

}


void BasicControlPanel::OnComponentLogAvailable(const QString& log)
{
    SettingComponentAbs* component = qobject_cast<SettingComponentAbs*>(sender());
    qDebug() << component->Id() << log;
}

void BasicControlPanel::OnComponentValueChanged(int id, int value)
{
    SettingComponentAbs* component = qobject_cast<SettingComponentAbs*>(sender());
    //
    QJsonObject obj;
    obj.insert("data", value);
    emit SendEvent(obj);
}

void BasicControlPanel::HandleEvent(const QJsonObject& obj) {
    //
}