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

#define TF_DTYPE_OBJECT_P(zv) tf_dtype_object_fetch_object(Z_OBJ_P(zv))

typedef struct _t_tf_dtype {
    TF_DataType type;
    zend_string* str;
    int ref;
} t_tf_dtype;

typedef struct _t_tf_dtype_object {
    zend_object std;
    t_tf_dtype* ptr;
} t_tf_dtype_object;

// class entry
extern zend_class_entry *ce_TF_Dtype;

static PHP_METHOD(TensorFlow_Dtype, __construct);
static PHP_METHOD(TensorFlow_Dtype, __toString);

void define_tf_dtype_class();

t_tf_dtype_object* tf_dtype_object_fetch_object(zend_object *obj);
size_t tf_dtype_sizeof(TF_DataType type);

#endif  /* PHP_TENSORFLOW_DTYPE_H */
