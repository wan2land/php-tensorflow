#ifndef PHP_TENSORFLOW_H
#define PHP_TENSORFLOW_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "tensorflow/c/c_api.h" // use this only

#define PHP_TENSORFLOW_VERSION "0.0.1"
#define PHP_TENSORFLOW_EXTNAME "tensorflow"

#ifndef PHP_TENSORFLOW_VERSION_STRING
#define PHP_TENSORFLOW_VERSION_STRING "unknown"
#endif

#define TENSORFLOW_NS "TensorFlow"

static PHP_MINFO_FUNCTION(tensorflow);
static PHP_MINIT_FUNCTION(tensorflow);
static PHP_FUNCTION(debug);

extern zend_module_entry tensorflow_module_entry;

#endif	/* PHP_TENSORFLOW_H */
