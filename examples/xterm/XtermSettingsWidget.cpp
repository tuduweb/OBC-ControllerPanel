#include "XtermSettingsWidget.hpp"

#include <QCoreApplication>

XtermSettingsWidget::XtermSettingsWidget(QWidget* parent)
    : QWidget(parent) {

	const auto componentJson = JsonFromString(StringFromFile(QCoreApplication::applicationDirPath() + "/component/pscamera.settings.json"));

    QGridLayout* layout = new QGridLayout(this); // equal setLayout
    setContentsMargins(0, 0, 0, 0);
    //setLayout(layout);

    layout->addWidget(new QLabel("hello world", this), 0, 0);

    {
        ButtonComponent* switchComponent = new ButtonComponent(123,
			{ {"displayName" , "NUC 非均匀性校正"} }, this);
		//ui->mainLayout->addWidget(switchComponent);
		layout->addWidget(switchComponent, 1, 0, 1, 2);// 1 0 开始 占用 1行 2列
    }
}