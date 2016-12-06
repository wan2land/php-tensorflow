#ifndef PHP_TENSORFLOW_H
#define PHP_TENSORFLOW_H

extern zend_module_entry tensorflow_module_entry;
#define phpext_tensorflow_ptr &tensorflow_module_entry

#define PHP_TENSORFLOW_VERSION "0.0.1"
#define PHP_TENSORFLOW_EXTNAME "tensorflow"

#ifndef PHP_TENSORFLOW_VERSION_STRING
#define PHP_TENSORFLOW_VERSION_STRING "unknown"
#endif

#define TENSORFLOW_NS "Tensorflow"

PHP_MINIT_FUNCTION(tensorflow);
PHP_MINFO_FUNCTION(tensorflow);

// PHP_FUNCTION(tensorflow_version);

#endif	/* PHP_TENSORFLOW_H */
