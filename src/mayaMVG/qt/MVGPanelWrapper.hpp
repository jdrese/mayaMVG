#pragma once

#include <QObject>
#include <maya/MCallbackIdArray.h>
#include <maya/MEventMessage.h>

namespace mayaMVG
{

class MVGPanelWrapper : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QString label READ getLabel NOTIFY labelChanged)
    Q_PROPERTY(bool isVisible READ getIsVisible)
    Q_PROPERTY(bool isPointCloudDisplayed READ isPointCloudDisplayed WRITE displayPointCloud NOTIFY
                   isPointCloudDisplayedChanged)

public:
    MVGPanelWrapper(const QString& name);
    MVGPanelWrapper(const QString& name, const QString& label);
    ~MVGPanelWrapper();

public:
    void emitIsPointCloudDisplayedChanged();

public Q_SLOTS:
    inline QString getName() const { return _name; }
    inline QString getLabel() const { return _label; }
    void setLabel(QString label);
    inline const bool getIsVisible() const { return _isVisible; }
    bool isPointCloudDisplayed() const;
    void displayPointCloud(const bool display);

Q_SIGNALS:
    void isPointCloudDisplayedChanged();
    void labelChanged();

private:
    QString _name;
    QString _label;
    bool _isVisible;
};

} // namespace
