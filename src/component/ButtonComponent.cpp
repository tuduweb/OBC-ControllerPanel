#include "ButtonComponent.hpp"

#include <QLayout>
#include <QPushButton>


ButtonComponent::ButtonComponent(int _id, const QJsonObject& settings, QWidget* parent)
	: SettingComponentAbs(_id, settings, parent)
	//, id(_id)
{
	LoadSettings(settings);

	QHBoxLayout* layout = new QHBoxLayout(this);
	this->setLayout(layout);

	QPushButton* button = new QPushButton(displayName, this);
	layout->addWidget(button);

	connect(button, &QPushButton::clicked, this, [=]() {
		OnLogAvailable(QString("<%1>按钮被点击").arg(displayName));
		ValueChanged(id, 1);
		});
}

ButtonComponent::~ButtonComponent()
{
}

bool ButtonComponent::LoadSettings(const QJsonObject& settings)
{
	if (settings.contains("displayName")) displayName = settings.value("displayName").toString();

	return true;
}
