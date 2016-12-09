
#include "php_tensorflow.h"

#include "class/tf_dtype.h"
#include "class/tf_status.h"
#include "class/tf_buffer.h"
#include "class/tf_tensor.h"

// functions
static zend_function_entry tf_functions[] = {
    {NULL, NULL, NULL}
};

// the following code creates an entry for the module and registers it with Zend.
zend_module_entry tensorflow_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TENSORFLOW_EXTNAME,
    tf_functions,
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

static PHP_MINFO_FUNCTION(tensorflow)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "TensorFlow Support", "enabled");
    php_info_print_table_row(2, "TensorFlow Module Version", PHP_TENSORFLOW_VERSION);
    php_info_print_table_end();

    php_info_print_table_start();
    php_info_print_table_header(3, "Version Info", "Compiled", "Linked");
    php_info_print_table_row(3, "TensorFlow Library", PHP_TENSORFLOW_VERSION_STRING, TF_Version());
    php_info_print_table_end();

    DISPLAY_INI_ENTRIES();
}

static PHP_MINIT_FUNCTION(tensorflow)
{
    REGISTER_NS_STRING_CONSTANT("TensorFlow", "VERSION", (char *)TF_Version(), CONST_PERSISTENT | CONST_CS);

    define_tf_dtype_class();
    define_tf_status_class();
    define_tf_buffer_class();
    define_tf_tensor_class();

    return SUCCESS;
}


// // --------------------------------------------------------------------------
// // Encode the string `src` (`src_len` bytes long) into `dst` in the format
// // required by TF_STRING tensors. Does not write to memory more than `dst_len`
// // bytes beyond `*dst`. `dst_len` should be at least
// // TF_StringEncodedSize(src_len).
// //
// // On success returns the size in bytes of the encoded string.
// // Returns an error into `status` otherwise.
// extern size_t TF_StringEncode(const char* src, size_t src_len, char* dst,
//                               size_t dst_len, TF_Status* status);

// // Decode a string encoded using TF_StringEncode.
// //
// // On success, sets `*dst` to the start of the decoded string and `*dst_len` to
// // its length. Returns the number of bytes starting at `src` consumed while
// // decoding. `*dst` points to memory within the encoded buffer.  On failure,
// // `*dst` and `*dst_len` are undefined and an error is set in `status`.
// //
// // Does not read memory more than `src_len` bytes beyond `src`.
// extern size_t TF_StringDecode(const char* src, size_t src_len, const char** dst,
//                               size_t* dst_len, TF_Status* status);

// // Return the size in bytes required to encode a string `len` bytes long into a
// // TF_STRING tensor.
// extern size_t TF_StringEncodedSize(size_t len);
