#ifndef PHP_TENSORFLOW_DTYPE_H
#define PHP_TENSORFLOW_DTYPE_H

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_exceptions.h>

#include "tensorflow/c/c_api.h" // use this only

typedef struct _t_tf_dtype {
    TF_DataType type;
    zend_string* str;
    int ref;
} t_tf_dtype;

typedef struct _t_tf_dtype_object {
    zend_object std;
    t_tf_dtype* ptr;
} t_tf_dtype_object;

static PHP_METHOD(Tensorflow_Dtype, __construct);
static PHP_METHOD(Tensorflow_Dtype, __toString);

void define_tf_dtype_class();

#endif  /* PHP_TENSORFLOW_DTYPE_H */
