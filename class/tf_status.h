#ifndef PHP_TENSORFLOW_STATUS_H
#define PHP_TENSORFLOW_STATUS_H

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "tensorflow/c/c_api.h" // use this only

typedef struct _t_tf_status {
	TF_Status* src;
	zend_string* str;
	int ref;
} t_tf_status;

typedef struct _t_tf_status_object {
	zend_object std;
	t_tf_status* ptr;
} t_tf_status_object;

static PHP_METHOD(TensorFlow_Status, __construct);
static PHP_METHOD(TensorFlow_Status, setCode);
static PHP_METHOD(TensorFlow_Status, getCode);
static PHP_METHOD(TensorFlow_Status, getMessage);

void define_tf_status_class();

#endif	/* PHP_TENSORFLOW_STATUS_H */
