qml-extra-data-structures
=========================

QML data structures and utilities that are either useful or are missing an official QML API.
It is tested with Qt 5.10.0 on the following:

  - Ubuntu 17.10
  - ~~Android 6.0.1 (arm-v7) built with SDK API 23 and NDK r10e on Ubuntu 17.10 host~~ Not yet

build
-----

```
    $ mkdir build && cd build
    $ qmake ..
    $ make install
```

This will install the QML plugin inside the Qt sysroot. **Be aware that this is not a sandboxed installation.**

See [samples/](samples/) for example uses (coming soon).

See [DOCUMENTATION.md](DOCUMENTATION.md) for the API.
