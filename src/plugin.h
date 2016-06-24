
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

#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>

#include "reactmoduleloader.h"
#include "reactsoundmanager.h"


class SoundModuleLoader
  : public QObject
  , public ReactModuleLoader
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID ReactModuleLoader_IID)
  Q_INTERFACES(ReactModuleLoader)

public:
  QObjectList availableModules() override;
};

#endif //  PLUGIN_H
