#pragma once
#include "PanelInterface.hpp"

#include <QVBoxLayout>

#include <QCoreApplication>

using namespace OBC::Panel;
namespace OBC::Panel::ControlPanel{
    class UVCControlPanel : public PanelInterface, public QWidget {
    
    public:
        UVCControlPanel(QWidget* parent = nullptr) : QWidget(parent) {
            QVBoxLayout* layout = new QVBoxLayout;
            setLayout(layout);

            layout->addWidget(new QLabel("hello Panel", this));

            //get Config
	        const auto componentJson = JsonFromString(StringFromFile( QCoreApplication::applicationDirPath() + "/UVCtest.settings.json"));

            //get settings



        };
        ~UVCControlPanel() = default;

    public:
        void ReloadGui() {
            if( !_settings.contains("control") ) {
                return;
            }

            const QJsonArray& controlElms = _settings["control"].toArray();

            // for(const auto& elmObj : controlElms) {
            //     const auto& elm = elmObj.toArray();
            //     SettingComponentAbs* component = new NumberSettingComponent();
            // }

            for(int i = 0; i < controlElms.size(); ++i) {
                const auto& elm = controlElms[i].toArray();
                if(elm.isEmpty()) continue;
                SettingComponentAbs* component = new NumberSettingComponent(i, 
                    {{"minValue", elm[1]} , {"maxValue", elm[2]}, {"displayName" , QString("elm-%1").arg(i)}}
                    , this);
                
                this->layout()->addWidget(component);

                
                components.append(component);
            }



        };

    public:
        bool loadSettings(const QJsonObject& settingsObj) override { if(settingsObj.isEmpty()) return false; _settings = settingsObj; return true; };

    protected:
        QJsonObject _settings;
        QVector<SettingComponentAbs*> components;
    };
};
