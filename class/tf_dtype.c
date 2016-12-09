
#include "tf_dtype.h"

zend_object* tf_dtype_object_create(zend_class_entry* ce TSRMLS_DC);
static void tf_dtype_object_free(zend_object *object TSRMLS_DC);
static t_tf_dtype* tf_dtype_ctor(TSRMLS_D);
static void tf_dtype_dtor(t_tf_dtype* tf_dtype TSRMLS_DC);

// class entries
zend_class_entry *ce_TF_Dtype = NULL;

static zend_object_handlers oh_TF_Dtype;

t_tf_dtype_object* tf_dtype_object_fetch_object(zend_object *obj)
{
    return (t_tf_dtype_object*)((char *)obj - XtOffsetOf(t_tf_dtype_object, std));
}

/**
 * @ref https://github.com/tensorflow/tensorflow/blob/287db3a9b0701021f302e7bb58af5cf89fdcd424/tensorflow/java/src/main/native/tensor_jni.cc
 */
size_t tf_dtype_sizeof(TF_DataType type)
{
    switch (type) {
        case TF_INT8 :
        case TF_UINT8 :
        case TF_QINT8 :
        case TF_QUINT8 :
        case TF_BOOL :
            return 1;
        case TF_INT16 :
        case TF_BFLOAT16 :
        case TF_QINT16 :
        case TF_QUINT16 :
        case TF_UINT16 :
            return 2;
        case TF_FLOAT :
        case TF_INT32 :
        case TF_QINT32 :
            return 4;
        case TF_DOUBLE :
        case TF_INT64 :
        case TF_COMPLEX64 : // equal TF_COMPLEX
            return 8;
        case TF_COMPLEX128 :
            return 16;
        default:
            break;
        // @todo
        // case TF_STRING : nbytes = uintptr(nflattened*8) + byteSizeOfEncodedStrings(value)
        // case TF_HALF :
        // case TF_RESOURCE :
    }
    return 0; // unknown;
}

// argument info
ZEND_BEGIN_ARG_INFO_EX(arginfo_tf_dtype___construct, 0, 0, 1)
    ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

// methods
static zend_function_entry tf_dtype_methods[] = {
    PHP_ME(TensorFlow_Dtype, __construct, arginfo_tf_dtype___construct, ZEND_ACC_PUBLIC)
    PHP_ME(TensorFlow_Dtype, __toString,  NULL,                         ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void define_tf_dtype_class()
{
    zend_class_entry temp_ce;

    INIT_NS_CLASS_ENTRY(temp_ce, "TensorFlow", "Dtype", tf_dtype_methods);

    ce_TF_Dtype = zend_register_internal_class(&temp_ce);
    ce_TF_Dtype->create_object = tf_dtype_object_create;

    #define TF_DTYPE_CLASS_CONST(name, value) zend_declare_class_constant_long(ce_TF_Dtype, name, sizeof(name) - 1, value);

    TF_DTYPE_CLASS_CONST("FLOAT", 1);
    TF_DTYPE_CLASS_CONST("DOUBLE", 2);
    TF_DTYPE_CLASS_CONST("INT32", 3);  // Int32 tensors are always in 'host' memory.
    TF_DTYPE_CLASS_CONST("UINT8", 4);
    TF_DTYPE_CLASS_CONST("INT16", 5);
    TF_DTYPE_CLASS_CONST("INT8", 6);
    TF_DTYPE_CLASS_CONST("STRING", 7);
    TF_DTYPE_CLASS_CONST("COMPLEX64", 8);  // Single-precision complex
    TF_DTYPE_CLASS_CONST("COMPLEX", 8);    // Old identifier kept for API backwards compatibility
    TF_DTYPE_CLASS_CONST("INT64", 9);
    TF_DTYPE_CLASS_CONST("BOOL", 10);
    TF_DTYPE_CLASS_CONST("QINT8", 11);     // Quantized int8
    TF_DTYPE_CLASS_CONST("QUINT8", 12);    // Quantized uint8
    TF_DTYPE_CLASS_CONST("QINT32", 13);    // Quantized int32
    TF_DTYPE_CLASS_CONST("BFLOAT16", 14);  // Float32 truncated to 16 bits, Only for cast ops.
    TF_DTYPE_CLASS_CONST("QINT16", 15);    // Quantized int16
    TF_DTYPE_CLASS_CONST("QUINT16", 16);   // Quantized uint16
    TF_DTYPE_CLASS_CONST("UINT16", 17);
    TF_DTYPE_CLASS_CONST("COMPLEX128", 18);  // Double-precision complex
    TF_DTYPE_CLASS_CONST("HALF", 19);
    TF_DTYPE_CLASS_CONST("RESOURCE", 20);

    memcpy(&oh_TF_Dtype, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    oh_TF_Dtype.clone_obj = NULL;
    oh_TF_Dtype.free_obj = tf_dtype_object_free;
    oh_TF_Dtype.offset = XtOffsetOf(t_tf_dtype_object, std);
}

zend_object* tf_dtype_object_create(zend_class_entry *ce TSRMLS_DC)
{
    t_tf_dtype_object *intern;

    intern = (t_tf_dtype_object *)ecalloc(1, sizeof(t_tf_dtype_object));
    intern->ptr = tf_dtype_ctor(TSRMLS_C);

    zend_object_std_init(&intern->std, ce TSRMLS_CC);
    object_properties_init(&intern->std, ce);

    intern->std.handlers = &oh_TF_Dtype;

    return &intern->std;
}

static void tf_dtype_object_free(zend_object *object TSRMLS_DC)
{
    t_tf_dtype_object *intern = tf_dtype_object_fetch_object(object);
    tf_dtype_dtor(intern->ptr TSRMLS_CC);
    zend_object_std_dtor(&intern->std TSRMLS_CC);
}

static t_tf_dtype* tf_dtype_ctor(TSRMLS_D)
{
    t_tf_dtype *php_tf_dtype = NULL;
    php_tf_dtype = (t_tf_dtype *)ecalloc(1, sizeof(t_tf_dtype));
    if (php_tf_dtype == NULL) {
        return NULL;
    }

    php_tf_dtype->type = 0;
    php_tf_dtype->str = NULL;
    php_tf_dtype->ref = 1;

    return php_tf_dtype;
}

static void tf_dtype_dtor(t_tf_dtype* tf_dtype TSRMLS_DC)
{
    tf_dtype->ref--;
    if (tf_dtype->ref == 0) {
        if (tf_dtype->str != NULL) {
            zend_string_release(tf_dtype->str);
        }
        efree(tf_dtype);
    }
}

static PHP_METHOD(TensorFlow_Dtype, __construct)
{
    // arguments
    zend_long type;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(type)
    ZEND_PARSE_PARAMETERS_END();

    if (type < 1 || type > 20) {
        zend_throw_exception(spl_ce_InvalidArgumentException, "type must be from 1 to 20", 0);
        return;
    }

    // this
    t_tf_dtype_object* intern;
    t_tf_dtype* php_tf_dtype;

    intern = TF_DTYPE_OBJECT_P(getThis());
    php_tf_dtype = intern->ptr;
    php_tf_dtype->type = type;
}

static PHP_METHOD(TensorFlow_Dtype, __toString)
{
    zend_string* result;

    // this
    t_tf_dtype_object* intern;
    t_tf_dtype* php_tf_dtype;

    intern = TF_DTYPE_OBJECT_P(getThis());
    php_tf_dtype = intern->ptr;

    RETURN_LONG(php_tf_dtype->type);
}
