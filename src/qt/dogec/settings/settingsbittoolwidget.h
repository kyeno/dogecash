// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2022 The DogeCash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SETTINGSBITTOOLWIDGET_H
#define SETTINGSBITTOOLWIDGET_H

#include <QWidget>
#include "qt/dogec/pwidget.h"
#include "qt/dogec/contactsdropdown.h"
#include "key.h"

namespace Ui {
class SettingsBitToolWidget;
}

class SettingsBitToolWidget : public PWidget
{
    Q_OBJECT

public:
    explicit SettingsBitToolWidget(DogeCashGUI* _window, QWidget *parent = nullptr);
    ~SettingsBitToolWidget();
protected:
    void resizeEvent(QResizeEvent *event) override;
public Q_SLOTS:
    void onEncryptSelected(bool isEncr);
    void setAddress_ENC(const QString& address);
    void onEncryptKeyButtonENCClicked();
    void onClearAll();
    void onClearDecrypt();
    void onAddressesClicked();
    void onDecryptClicked();
    void importAddressFromDecKey();

private:
    Ui::SettingsBitToolWidget *ui;
    QAction *btnContact;
    ContactsDropdown *menuContacts = nullptr;

    // Cached key
    CKey key;

    void resizeMenu();
};

#endif // SETTINGSBITTOOLWIDGET_H
