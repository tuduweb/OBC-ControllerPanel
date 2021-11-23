#include "XthermSettingsWidget.hpp"

#include <QCoreApplication>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

XthermSettingsWidget::XthermSettingsWidget(QWidget* parent)
    : QWidget(parent) {

	const auto componentJson = JsonFromString(StringFromFile(QCoreApplication::applicationDirPath() + "/component/pscamera.settings.json"));

    QGridLayout* layout = new QGridLayout(this); // equal setLayout
    setContentsMargins(0, 0, 0, 0);
    //setLayout(layout);

    layout->addWidget(new QLabel("hello world", this), 0, 0);
    {
        ButtonComponent* component = new ButtonComponent(123,
			{ {"displayName" , QString("NUC")} }, this);

		layout->addWidget(component, 1, 0, 1, 2);
        // 1 0 开始 占用 1行 2列
    }

    {
        SwitchSettingComponent* component = new SwitchSettingComponent(123,
			{ {"displayName" , QString("Auto Correction")} }, this);

		layout->addWidget(component, 2, 0, 1, 1);

    }

    {
        NumberSettingComponent* component = new NumberSettingComponent(124,
            {
                {"displayName", "Time"},
                {"minValue", 60},
                {"maxValue", 1000},
                {"unitTxt", "s"}
            }, this);

        layout->addWidget(component, 2, 1);
    }

    {
        SwitchSettingComponent* component = new SwitchSettingComponent(123,
			{ {"displayName" , QString("Measure Temp")} }, this);

		layout->addWidget(component, 3, 0, 1, 2);
    }

    {
        ButtonComponent* component = new ButtonComponent(123,
			{ {"displayName" , QString("Param Update")} }, this);

		layout->addWidget(component, 4, 0, 1, 2);
        // 1 0 开始 占用 1行 2列
    }
}