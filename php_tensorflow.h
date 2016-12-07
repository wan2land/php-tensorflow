#ifndef PHP_TENSORFLOW_H
#define PHP_TENSORFLOW_H

#include "tensorflow/c/c_api.h" // use this only


extern zend_module_entry tensorflow_module_entry;


#define phpext_tensorflow_ptr &tensorflow_module_entry

#define PHP_TENSORFLOW_VERSION "0.0.1"
#define PHP_TENSORFLOW_EXTNAME "tensorflow"

#ifndef PHP_TENSORFLOW_VERSION_STRING
#define PHP_TENSORFLOW_VERSION_STRING "unknown"
#endif

#define TENSORFLOW_NS "Tensorflow"

#define STRLEN(s) (sizeof(s)/sizeof(s[0]))

typedef TF_Code php_tf_code;

typedef struct _php_tf_status {
	TF_Status* ptr;
	zend_string* str;
	int ref;
} php_tf_status;

typedef struct _php_tf_status_object {
	zend_object std;
	php_tf_status* ptr;
} php_tf_status_object;



static PHP_MINFO_FUNCTION(tensorflow);
static PHP_MINIT_FUNCTION(tensorflow);

static PHP_METHOD(Tensorflow_Status, set);
static PHP_METHOD(Tensorflow_Status, getCode);
static PHP_METHOD(Tensorflow_Status, getMessage);

#endif	/* PHP_TENSORFLOW_H */
