#pragma once
#include "PanelInterface.hpp"

#include <QVBoxLayout>

#include <QCoreApplication>

#include "component/NumberSettingComponent.hpp"

#include <QCheckBox>

namespace OBC::Panel::Component{
    class UVCBasicSettingComponent : public QWidget
    {
        Q_OBJECT
    
    public:
        UVCBasicSettingComponent(int id, const QJsonObject& settings, QWidget* parent = nullptr)
            : QWidget(parent), basicComponent(nullptr), layout(new QHBoxLayout(this))
        {
            setLayout(layout);

            const QJsonArray& config = settings["config"].toArray();

            setToolTip(QString("Range : %1 to %2").arg(config[1].toInt()).arg(config[2].toInt()));

            basicComponent = new NumberSettingComponent(id,
                {
                    {"minValue", config[1]},
                    {"maxValue", config[2]},
                    {"displayName" , settings["displayName"]}
                }, this);

            //component -> panel
            connect(basicComponent, &SettingComponentAbs::ValueChanged, this, &UVCBasicSettingComponent::valueChanged);            

            //

            layout->addWidget(basicComponent);
            layout->addWidget(new QCheckBox(this));
            
        }

    protected:
        NumberSettingComponent* basicComponent;
        QHBoxLayout* layout;

    public slots:
        //void OnKernelValuedChanged(int id, int value) {};
    signals:
        void valueChanged(int id, int value);
        void OnKernelValuedChanged(int id, int value) { if(id != basicComponent->Id()) return; basicComponent->SetValue(value); };
    };
};


using namespace OBC::Panel;
using namespace OBC::Panel::Component;

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

            if(components.size() > 0) {
                //delete all
            }

            const QJsonArray& controlElms = _settings["control"].toArray();

            // for(const auto& elmObj : controlElms) {
            //     const auto& elm = elmObj.toArray();
            //     SettingComponentAbs* component = new NumberSettingComponent();
            // }

            for(int i = 0; i < controlElms.size(); ++i) {
                const auto& elm = controlElms[i].toArray();
                if(elm.isEmpty()) continue;
                UVCBasicSettingComponent* component = new UVCBasicSettingComponent(i, 
                    { {"config", elm},{"minValue", elm[1]} , {"maxValue", elm[2]}, {"displayName" , QString("elm-%1").arg(i)}}
                    , this);
                
                this->layout()->addWidget(component);

                components.append(component);
            }



        };

    public:
        bool loadSettings(const QJsonObject& settingsObj) override { if(settingsObj.isEmpty()) return false; _settings = settingsObj; return true; };

    protected:
        QJsonObject _settings;
        QVector<UVCBasicSettingComponent*> components;
    };
};
