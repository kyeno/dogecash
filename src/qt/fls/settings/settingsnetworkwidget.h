// Copyright (c) 2019 The PIVX Developers
// Copyright (c) 2019 The Flits Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SETTINGSNETWORKWIDGET_H
#define SETTINGSNETWORKWIDGET_H

#include <QWidget>
#include <QDataWidgetMapper>
#include "qt/fls/pwidget.h"

namespace Ui {
class SettingsNetworkWidget;
}

class SettingsNetworkWidget : public PWidget
{
    Q_OBJECT

public:
    explicit SettingsNetworkWidget(flsGUI* _window, QWidget *parent = nullptr);
    ~SettingsNetworkWidget();

    void setMapper(QDataWidgetMapper *mapper);

private:
    Ui::SettingsNetworkWidget *ui;

Q_SIGNALS:
    void saveSettings() {};
};

#endif // SETTINGSNETWORKWIDGET_H