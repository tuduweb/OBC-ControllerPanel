#pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

#include "SettingComponentAbs.hpp"

#include <QWidget>

#include <QVariant>
#include <QLabel>

#include <QJsonObject>
#include <QJsonArray>

#include <QRadioButton>
#include <QButtonGroup>
class MultiSelectComponent : public SettingComponentAbs
{
	Q_OBJECT

public:
	MultiSelectComponent(int id, const QJsonObject& settings, QWidget* parent);
	~MultiSelectComponent();

	bool LoadSettings(const QJsonObject& settings) override;

signals:
	void ValueChanged(int id, int value);
	void OnLogAvailable(const QString& log);

public slots:
	void OnDataChanged(const QVariant& data);
	void SetValue(int value) override;


protected:
	QMap<QString, QRadioButton*> buttons;
	QButtonGroup* buttonGroup;

private:
	QLabel* label = nullptr;
	const int id;

	QString displayName;

	QStringList selectList;
	QJsonObject multiList;
};
