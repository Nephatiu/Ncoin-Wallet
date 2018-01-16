// Copyright © 2011-2016 The Cryptonote developers
// Copyright © 2015-2016 XDN developers
// All Rights Reversed ® GGTM.eu Underground Services
// Distributed under the MIT/X11 software license,
// see http://www.opensource.org/licenses/mit-license.php.

#include "NewPoolDialog.h"

#include "ui_newpooldialog.h"

namespace WalletGui {

NewPoolDialog::NewPoolDialog(QWidget* _parent) : QDialog(_parent), m_ui(new Ui::NewPoolDialog) {
  m_ui->setupUi(this);
}

NewPoolDialog::~NewPoolDialog() {
}

QString NewPoolDialog::getHost() const {
  return m_ui->m_hostEdit->text().trimmed();
}

quint16 NewPoolDialog::getPort() const {
  return m_ui->m_portSpin->value();
}

}
