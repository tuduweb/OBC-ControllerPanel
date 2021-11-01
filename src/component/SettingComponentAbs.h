#pragma once

#include <QWidget>
#include "base/OBCBase.hpp"

DECL_IDTYPE(ComponentId);
Q_DECLARE_METATYPE(ComponentId);

class SettingComponentAbs : public QWidget
{
	Q_OBJECT

public:
	SettingComponentAbs(int id, const QJsonObject& settings, QWidget* parent);
	~SettingComponentAbs();

	virtual bool LoadSettings(const QJsonObject& settings) = 0;
	const int Id() { return id; }
signals:
	void OnLogAvailable(const QString& log);
	void ValueChanged(int id, int value);

public slots:
	//void SendEvent();
	virtual void SetValue(int value) = 0;

protected:
	QString displayName;
	const int id;
	QString componentKey;//在一个Settings中对应唯一值
};
