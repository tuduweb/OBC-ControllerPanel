#include "NumberSettingComponent.h"
#include "qdebug.h"

HexSpinBox::HexSpinBox(QWidget* parent)
	: QSpinBox(parent)
{
	setRange(0, 255);
	validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}
QValidator::State HexSpinBox::validate(QString& text, int& pos) const
{
	return validator->validate(text, pos);
}
QString HexSpinBox::textFromValue(int value) const
{
	return QString::number(value, 16).toUpper();
}
int HexSpinBox::valueFromText(const QString& text) const
{
	bool ok;
	return text.toInt(&ok, 16);
}


NumberSettingComponent::NumberSettingComponent(int _id, const QJsonObject& settings, QWidget* parent)
	: SettingComponentAbs(_id, settings, parent)
	, id(_id)
	, maxValue(0)
	, minValue(0)
	, spinBoxType(0)
{
	LoadSettings(settings);

	setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* layout = new QHBoxLayout(this);
	this->setLayout(layout);

	label = new QLabel(displayName, this);
	label->setMinimumWidth(60);

	slider = new QSlider(Qt::Horizontal, this);
	slider->setMaximum(maxValue);
	slider->setMinimum(minValue);
	slider->setPageStep((maxValue - minValue) / 10);


	//txt = new QLineEdit(QString::number(slider->value()), this);

	if (spinBoxType == 1)
		spin = new HexSpinBox(this);
	else
		spin = new QSpinBox(this);


	spin->setMaximum(maxValue);
	spin->setMinimum(minValue);

	layout->addWidget(label);
	layout->addWidget(slider);
	//layout->addWidget(txt);
	layout->addWidget(spin);

	if (!unitTxt.isNull())
	{
		layout->addWidget(new QLabel(unitTxt, this));
		//layout->setStretch(3, 0);
	}


	layout->setStretch(0, 0);
	layout->setStretch(1, 4);
	layout->setStretch(2, 1);
	//layout->setStretch(3, 1);
	//layout->setStretch(4, 1);

	{
		//button = new QPushButton("设置", this);
		//layout->addWidget(button);
	}

	connect(slider, &QSlider::valueChanged, [=](const int& value) {
		//txt->setText(QString::number(value));
		spin->setValue(value);
		OnLogAvailable(QString("<%1>值改变为(%2%3)").arg(displayName).arg(value).arg(unitTxt));
		this->ValueChanged(id, value);
		});

	connect(spin, qOverload<int>(&QSpinBox::valueChanged), [=](const int& value) {
		slider->setValue(value);
		});


}

NumberSettingComponent::~NumberSettingComponent()
{
}

void NumberSettingComponent::setRange(int min, int max)
{
	slider->setMaximum(max);
	slider->setMinimum(min);

	spin->setMaximum(max);
	spin->setMinimum(min);
}

void NumberSettingComponent::SetValue(int value)
{
	spin->setValue(value);
	slider->setValue(value);
}

//后期需要适应浮点类型
bool NumberSettingComponent::LoadSettings(const QJsonObject& settings)
{
	if (settings.contains("displayName")) displayName = settings.value("displayName").toString();
	if (settings.contains("maxValue")) maxValue = settings.value("maxValue").toInt();
	if (settings.contains("minValue")) minValue = settings.value("minValue").toInt();
	if (settings.contains("unitTxt")) unitTxt = settings.value("unitTxt").toString();
	if (settings.contains("spinBoxType")) spinBoxType = settings.value("spinBoxType").toInt();

	return true;
}
