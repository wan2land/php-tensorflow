PHP Tensorflow
==============

use `tensorflow` `0.12.0-rc0` c api.

# Installation

**install tensorflow as submodule.**

```sh
git submodule update --init --recursive
cd lib/tensorflow
./configure
bazel build -c opt //tensorflow:libtensorflow.so
cp bazel-bin/tensorflow/libtensorflow.so /usr/local/lib
```

**build the php extension.**

```sh
phpize
./configure
make install
```
