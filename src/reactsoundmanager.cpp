
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

#include <QMap>
#include <QVariant>
#include <QUrl>
#include <QtMultimedia/QSoundEffect>

#include <QDebug>

#include "reactsoundmanager.h"

#include "reactbridge.h"


class ReactSoundManagerPrivate {
public:
  ReactBridge* bridge = nullptr;
  QMap<QUrl, QSoundEffect*> sounds;
};


void ReactSoundManager::playSound(
  const QUrl& soundUrl,
  const ReactModuleInterface::ListArgumentBlock& resolve,
  const ReactModuleInterface::ListArgumentBlock& reject
) {
  Q_D(ReactSoundManager);

  QUrl resolvedUrl = soundUrl;
  if (soundUrl.isRelative())
    resolvedUrl = QUrl::fromLocalFile(QFileInfo(soundUrl.toString()).absoluteFilePath());

  if (d->sounds.contains(resolvedUrl)) {
    d->sounds.value(resolvedUrl)->play();
    resolve(d->bridge, QVariantList{true});
  } else {
    QSoundEffect* se = new QSoundEffect(this);
    se->setSource(resolvedUrl);
    connect(se, &QSoundEffect::loadedChanged, [=] {
        if (se->isLoaded()) {
          d->sounds.insert(resolvedUrl, se);
          se->play();
          resolve(d->bridge, QVariantList{true});
        } else {
          reject(d->bridge, QVariantList{QVariantMap{{"error", "Failed to load sound"}}});
        }
      });
  }
}

void ReactSoundManager::clearCache()
{
  Q_D(ReactSoundManager);
  for (auto se : d->sounds) {
    delete se;
  }
  d->sounds.clear();
}


ReactSoundManager::ReactSoundManager(QObject* parent)
  : QObject(parent)
  , d_ptr(new ReactSoundManagerPrivate)
{
}

ReactSoundManager::~ReactSoundManager()
{
}

void ReactSoundManager::setBridge(ReactBridge* bridge)
{
  Q_D(ReactSoundManager);
  d->bridge = bridge;
}

ReactViewManager* ReactSoundManager::viewManager()
{
  return nullptr;
}

QString ReactSoundManager::moduleName()
{
  return "RCTSoundManager";
}

QList<ReactModuleMethod*> ReactSoundManager::methodsToExport()
{
  return QList<ReactModuleMethod*>{};
}

QVariantMap ReactSoundManager::constantsToExport()
{
  return QVariantMap{};
}

