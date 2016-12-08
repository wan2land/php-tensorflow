#ifndef PHP_TENSORFLOW_H
#define PHP_TENSORFLOW_H

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

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

static PHP_MINFO_FUNCTION(tensorflow);
static PHP_MINIT_FUNCTION(tensorflow);

#endif	/* PHP_TENSORFLOW_H */
