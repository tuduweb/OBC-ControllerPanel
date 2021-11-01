#include "SwitchSettingComponent.h"

#include <QPushButton>
#include <QLayout>
#include <QLabel>

#include <qDebug>

#include <QEventLoop>
#include <QTimer>
SwitchSettingComponent::SwitchSettingComponent(int _id, const QJsonObject& settings, QWidget* parent)
	: SettingComponentAbs(_id, settings, parent)
	, id(_id)
{
	LoadSettings(settings);

	setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* layout = new QHBoxLayout(this);
	this->setLayout(layout);

	label = new QLabel(this);
	label->setMinimumWidth(100);

	QPushButton* button_1 = new QPushButton(QString("%1开").arg(displayName), this);
	button_1->setProperty("value", 1);

	QPushButton* button_0 = new QPushButton(QString("%1关").arg(displayName), this);
	button_0->setProperty("value", 0);

	label->setMaximumHeight(button_1->height());

	layout->addWidget(label);
	layout->addWidget(button_1);
	layout->addWidget(button_0);

	//label->setStyleSheet("background-color:#ccc;");
	OnDataChanged(-1);

	layout->setStretch(0, 0);
	layout->setStretch(1, 1);
	layout->setStretch(2, 1);


	connect(button_0, &QPushButton::clicked, this, [=]() {
		OnDataChanged(0);
		this->ValueChanged(id, 0);
		});

	connect(button_1, &QPushButton::clicked, this, [=]() {
		qDebug() << "clicked";
		OnDataChanged(1);
		this->ValueChanged(id, 1);

		});
}

SwitchSettingComponent::~SwitchSettingComponent()
{
}

void SwitchSettingComponent::SetValue(int value)
{
	//二值选择..所以值只有两种..
	OnDataChanged(value > 0);
}

bool SwitchSettingComponent::LoadSettings(const QJsonObject& settings)
{
	if (settings.contains("displayName")) displayName = settings.value("displayName").toString();
	return true;
}

void SwitchSettingComponent::OnDataChanged(const QVariant& data)
{
	int size = 20;
	QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
	QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
	QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
	QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
	QString sizes = min_height + min_width + max_height + max_width;
	QString border_radis = QString("border-radius: %1px;").arg(size / 2);
	QString border = QString("border:1px solid black;");
	//data.
	if (1 == data.toInt())
	{
		label->setStyleSheet(sizes + border + border_radis + "background-color:green;");
		OnLogAvailable(QString("<%1>状态变化为(开)").arg(displayName));
	}
	else if (0 == data.toInt()) {
		label->setStyleSheet(sizes + border + border_radis + "background-color:#ff9717;");
		OnLogAvailable(QString("<%1>状态变化为(关)").arg(displayName));
	}
	else {
		label->setStyleSheet(sizes + border + border_radis + "background-color:#ccc;");
	}
}
