#pragma once

#include "SettingComponentAbs.h"

class ButtonComponent : public SettingComponentAbs
{
	Q_OBJECT

public:
	ButtonComponent(int id, const QJsonObject& settings, QWidget* parent);
	~ButtonComponent();

	bool LoadSettings(const QJsonObject& settings) override;

public slots:
	void OnDataChanged(const QVariant& data) {};
	void SetValue(int value) {};

	//protected slots:
};
