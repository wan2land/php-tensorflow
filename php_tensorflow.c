
#include "php_tensorflow.h"

#include "class/tf_dtype.h"
#include "class/tf_status.h"
#include "class/tf_buffer.h"
#include "class/tf_tensor.h"
#include "class/tf_graph.h"
#include "class/tf_operation_description.h"
#include "class/tf_session_options.h"
#include "class/tf_session.h"

// functions
static zend_function_entry tf_functions[] = {
    ZEND_NS_FE("TensorFlow", debug, NULL)
    ZEND_FE_END
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

    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_FLOAT", 1, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_DOUBLE", 2, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_INT32", 3, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_UINT8", 4, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_INT16", 5, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_INT8", 6, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_STRING", 7, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_COMPLEX64", 8, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_COMPLEX", 8, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_INT64", 9, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_BOOL", 10, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_QINT8", 11, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_QUINT8", 12, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_QINT32", 13, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_BFLOAT16", 14, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_QINT16", 15, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_QUINT16", 16, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_UINT16", 17, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_COMPLEX128", 18, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_HALF", 19, CONST_PERSISTENT | CONST_CS);
    REGISTER_NS_LONG_CONSTANT("TensorFlow", "DTYPE_RESOURCE", 20, CONST_PERSISTENT | CONST_CS);

    define_tf_status_class();
    define_tf_buffer_class();
    define_tf_tensor_class();
    define_tf_graph_class();
    define_tf_operation_description_class();
    define_tf_session_options_class();
    define_tf_session_class();

    return SUCCESS;
}

static PHP_FUNCTION(debug)
{
    // TF_Graph *graph = TF_NewGraph();

    // // placeholder
    // TF_OperationDescription* desc = TF_NewOperation(graph, "Placeholder", "feed");
    // TF_SetAttrType(desc, "dtype", TF_INT32);
    // TF_Operation *operation = TF_FinishOperation(desc, NULL); // second is status

    

    RETURN_STRING("Hello World!");
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
