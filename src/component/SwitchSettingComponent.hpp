#pragma once

#include "SettingComponentAbs.hpp"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

#include <QWidget>

#include <QVariant>
#include <QLabel>

#include <QJsonObject>

class SwitchSettingComponent : public SettingComponentAbs
{
	Q_OBJECT

public:
	SwitchSettingComponent(int id, const QJsonObject& settings, QWidget* parent);
	~SwitchSettingComponent();

	bool LoadSettings(const QJsonObject& settings);

signals:
	void ValueChanged(int id, int value);
	void OnLogAvailable(const QString& log);

public slots:
	void OnDataChanged(const QVariant& data);
	void SetValue(int value);

private:
	QLabel* label = nullptr;
	QString componentKey;
	const int id;

	QString displayName;

};
