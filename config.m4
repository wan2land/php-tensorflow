PHP_ARG_ENABLE(tensorflow, whether to enable php-tensorflow,
[  --enable-tensorflow     Enable php-tensorflow])

dnl Check whether the extension is enabled at all
if test "$PHP_TENSORFLOW" = "yes"; then

  dnl Finally, tell the build system about the extension and what files are needed

  AC_DEFINE(HAVE_TENSORFLOW, 1, [Whether you have php-tensorflow])

  PHP_ADD_INCLUDE(lib/tensorflow) # for c_api.h

  PHP_ADD_LIBRARY(tensorflow, 1, TENSORFLOW_SHARED_LIBADD)

  PHP_NEW_EXTENSION(tensorflow, php_tensorflow.c class/tf_status.c class/tf_buffer.c class/tf_dtype.c, $ext_shared)

  PHP_SUBST(TENSORFLOW_SHARED_LIBADD)

fi
