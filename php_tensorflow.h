#ifndef PHP_TENSORFLOW_H
#define PHP_TENSORFLOW_H

#define PHP_TENSORFLOW_VERSION "0.0.1"
#define PHP_TENSORFLOW_EXTNAME "tensorflow"

extern zend_module_entry tensorflow_module_entry;

#define phpext_tensorflow_ptr &tensorflow_module_entry

PHP_FUNCTION(tensorflow_version);

#endif	/* PHP_TENSORFLOW_H */
