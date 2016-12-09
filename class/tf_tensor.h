#ifndef PHP_TENSORFLOW_TENSOR_H
#define PHP_TENSORFLOW_TENSOR_H

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_exceptions.h>

#include "tf_dtype.h"
#include "tensorflow/c/c_api.h" // use this only

typedef struct _t_tf_tensor {
    TF_Tensor* src;
    zend_string* str;
    int ref;
} t_tf_tensor;

typedef struct _t_tf_tensor_object {
    zend_object std;
    t_tf_tensor* ptr;
} t_tf_tensor_object;

static PHP_METHOD(TensorFlow_Tensor, __construct);
// static PHP_METHOD(TensorFlow_Tensor, getType);
// static PHP_METHOD(TensorFlow_Tensor, getDims);
// static PHP_METHOD(TensorFlow_Tensor, getByteSize);
// static PHP_METHOD(TensorFlow_Tensor, getData);

void define_tf_tensor_class();

#endif  /* PHP_TENSORFLOW_TENSOR_H */
