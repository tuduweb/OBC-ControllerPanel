#pragma once

#include "SettingComponentAbs.hpp"

#include <QWidget>
#include <QLayout>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

#include <QJsonObject>

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

class HexSpinBox : public QSpinBox
{
public:
	HexSpinBox(QWidget* parent);
	~HexSpinBox();
	QValidator::State validate(QString& text, int& pos) const;
	QString textFromValue(int value) const;
	int valueFromText(const QString& text) const;
private:
	QRegExpValidator* validator;
};


class NumberSettingComponent : public SettingComponentAbs
{
	Q_OBJECT

public:
	NumberSettingComponent(int id, const QJsonObject& settings, QWidget* parent);
	~NumberSettingComponent();

	void setRange(int min, int max);
	bool LoadSettings(const QJsonObject& settings) override;

	//signals:
	//	void ValueChanged(int id, int value);
	//	void OnLogAvailable(const QString& log);

public slots:
	void SetValue(int value) override;

protected:
	QLabel* label;
	QSlider* slider;
	QLineEdit* txt;
	QSpinBox* spin;
	QPushButton* button;

	int maxValue;
	int minValue;

private:
	QString componentKey;
	const int id;
	QString displayName;
	QString unitTxt;//单位
	int spinBoxType;


};
