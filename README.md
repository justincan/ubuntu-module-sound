
# ubuntu-module-sound

React Native sound playback for Ubuntu.

## Installation

In your react native application directory.

```
npm install https://github.com/justincan/ubuntu-module-sound --save
```

## Usage

```js
import { playSound }  from 'ubuntu-sound';

function moo() {
  playSound("file:///usr/lib/libreoffice/share/gallery/sounds/cow.wav").then(() => {
      console.log("moo");
    });
}
```

## Notes

Still very alpha.

