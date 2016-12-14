TensorFlow PHP Extension
========================

use `tensorflow` `0.12.0-rc0` c api.

## Requirements

- [bazel](https://www.bazel.build/versions/master/docs/install.html)
- Environment to build TensorFlow from source code
  ([Linux](https://www.tensorflow.org/versions/master/get_started/os_setup.html#prepare-environment-for-linux)
  or [Mac OS
  X](https://www.tensorflow.org/versions/master/get_started/os_setup.html#prepare-environment-for-mac-os-x)).
  If you'd like to skip reading those details and do not care about GPU
  support, try the following:

  ```sh
  # On Linux
  sudo apt-get install python swig python-numpy

  # On Mac OS X with homebrew
  brew install swig
  ```

## Installation

1. Download and Build the TensorFlow by Git Submodule.

   ```sh
   git submodule update --init --recursive
   cd lib/tensorflow
   ./configure
   bazel build -c opt //tensorflow:libtensorflow.so
   cp bazel-bin/tensorflow/libtensorflow.so /usr/local/lib
   ```

2. Build the PHP Extension

   ```sh
   phpize
   ./configure
   make install
   ```

## Contributions

This API has been built on top of the [C API](https://www.tensorflow.org/code/tensorflow/c/c_api.h),
which is intended for building language bindings for TensorFlow functionality.
However, this is far from complete. Contributions are welcome.

## Documents

Current useable stuffs.

%% insert .ide-helper.php

## Reference

- [TensorFlow Go API](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/go)

## Todo

- [Operator Overloading](https://github.com/php/pecl-php-operator)
