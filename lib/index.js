
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
 * @providesModule Sound
 * @flow
 */

'use strict';

const SoundManager = require('react-native').NativeModules.SoundManager;

function playSound(soundUrl) {
  return SoundManager.playSound(soundUrl);
}

function clearCache() {
  SoundManager.clearCache();
}

module.exports = { playSound, clearCache };
