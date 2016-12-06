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
#include "php_tensorflow.h"


// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static zend_function_entry tensorflow_extensions[] = {
    // PHP_FE(tensorflow_version, NULL)
    {NULL, NULL, NULL}
};

// the following code creates an entry for the module and registers it with Zend.
zend_module_entry tensorflow_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TENSORFLOW_EXTNAME,
    tensorflow_extensions,
    PHP_MINIT(tensorflow),
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    PHP_MINFO(tensorflow),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_TENSORFLOW_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(tensorflow)

PHP_MINIT_FUNCTION(tensorflow)
{
    REGISTER_NS_STRING_CONSTANT("Tensorflow", "VERSION", (char *)TF_Version(), CONST_PERSISTENT | CONST_CS);

    return SUCCESS;
}

PHP_MINFO_FUNCTION(tensorflow)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "Tensorflow Support", "enabled");
    php_info_print_table_row(2, "Tensorflow Module Version", PHP_TENSORFLOW_VERSION);
    php_info_print_table_end();

    php_info_print_table_start();
    php_info_print_table_header(3, "Version Info", "Compiled", "Linked");
    php_info_print_table_row(3, "Tensorflow Library", PHP_TENSORFLOW_VERSION_STRING, TF_Version());
    php_info_print_table_end();

    DISPLAY_INI_ENTRIES();
}

// PHP_FUNCTION(tensorflow_version)
// {
//     RETURN_STRING(TF_Version());
// }
