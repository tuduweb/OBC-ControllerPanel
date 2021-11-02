#include "MultiSelectComponent.hpp"

#include <QPushButton>
#include <QLayout>
#include <QLabel>

#include <qDebug>
#include <QRadioButton>
#include <QButtonGroup>

MultiSelectComponent::MultiSelectComponent(int _id, const QJsonObject& settings, QWidget* parent)
	: SettingComponentAbs(_id, settings, parent)
	, id(_id)
	, buttonGroup(nullptr)
{
	LoadSettings(settings);


	QHBoxLayout* layout = new QHBoxLayout(this);
	this->setLayout(layout);

	label = new QLabel(displayName, this);
	label->setMinimumWidth(60);


	layout->addWidget(label);

	buttonGroup = new QButtonGroup(this);
	//for (const auto& item : selectList)
	//{
	//	//QLabel* t_label = new QLabel(item, this);
	//	//layout->addWidget(t_label);

	//	QRadioButton* radio = new QRadioButton(item, this);
	//	layout->addWidget(radio);
	//	group->addButton(radio);
	//}



	//还需要增加检查才行
	for (const auto& item : multiList.keys())
	{
		QRadioButton* radio = new QRadioButton(item, this);

		radio->setProperty("value", multiList.value(item).toInt());

		layout->addWidget(radio);
		buttonGroup->addButton(radio);
		buttons.insert(item, radio);

	}

	connect(buttonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked), this, [=](QAbstractButton* button) {
		//QRadioButton* radio = qobject_cast<QRadioButton*>(button);
		auto value = button->property("value").toInt();
		OnLogAvailable(QString("<%1>值改变为(%2)").arg(displayName).arg(button->text()));
		this->ValueChanged(id, value);//signal
		});

}


MultiSelectComponent::~MultiSelectComponent()
{
}


bool MultiSelectComponent::LoadSettings(const QJsonObject& settings)
{
	if (settings.contains("displayName")) displayName = settings.value("displayName").toString();

	QStringList tempList;

	settings.value("selections").toObject();

	for (const auto& item : settings.value("selections").toObject().keys())
	{
		tempList << item;
	}

	selectList = tempList;

	multiList = settings.value("selections").toObject();



	return true;
}

void MultiSelectComponent::OnDataChanged(const QVariant& data)
{
	//
}

//maybe need to notify others
//TODO: reform the structure of buttons, we need set key to 'value'?
void MultiSelectComponent::SetValue(int value)
{
	for (const auto& button : buttonGroup->buttons())
	{
		if (value == button->property("value").toInt())
		{
			button->setChecked(true);
			return;
		}
	}

	//can't find that value
	qWarning() << QString("can't find that value in %1 with value %2").arg(displayName).arg(value);
}
