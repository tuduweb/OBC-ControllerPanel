#include "SettingComponentAbs.h"

SettingComponentAbs::SettingComponentAbs(int _id, const QJsonObject& settings, QWidget* parent)
	: QWidget(parent)
	, id(_id)
{
	setContentsMargins(0, 0, 0, 0);
}

SettingComponentAbs::~SettingComponentAbs()
{
}
