
/**
 * Copyright (C) 2016, Canonical Ltd.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 * Author: Justin McPherson <justin.mcpherson@canonical.com>
 *
 */

#ifndef REACTSOUNDMANAGER_H
#define REACTSOUNDMANAGER_H

#include <QByteArray>
#include <QUrl>

#include "reactmoduleinterface.h"



class ReactSoundManagerPrivate;
class ReactSoundManager
  : public QObject
  , public ReactModuleInterface
{
  Q_OBJECT
  Q_INTERFACES(ReactModuleInterface)

  Q_INVOKABLE REACT_PROMISE
    void playSound(
      const QUrl& sound,
      const ReactModuleInterface::ListArgumentBlock& resolve,
      const ReactModuleInterface::ListArgumentBlock& reject);

  Q_INVOKABLE void clearCache();

  Q_DECLARE_PRIVATE(ReactSoundManager)

public:
  ReactSoundManager(QObject* parent = 0);
  ~ReactSoundManager();

  void setBridge(ReactBridge* bridge) override;

  // TODO: this doesnt seem right
  ReactViewManager* viewManager() override;

  QString moduleName() override;
  QList<ReactModuleMethod*> methodsToExport() override;
  QVariantMap constantsToExport() override;

private:
  QScopedPointer<ReactSoundManagerPrivate> d_ptr;
};

#endif // REACTSOUNDMANAGER_H
