
#include "tf_buffer.h"

zend_object* tf_buffer_object_create(zend_class_entry* ce TSRMLS_DC);
static void tf_buffer_object_free(zend_object *object TSRMLS_DC);
static t_tf_buffer* tf_buffer_ctor(TSRMLS_D);
static void tf_buffer_dtor(t_tf_buffer* tf_buffer TSRMLS_DC);

// class entries
static zend_class_entry *ce_TF_Buffer = NULL;

static zend_object_handlers oh_TF_Buffer;

static inline t_tf_buffer_object* tf_buffer_object_fetch_object(zend_object *obj) {
    return (t_tf_buffer_object*)((char *)obj - XtOffsetOf(t_tf_buffer_object, std));
}
#define TF_BUFFER_OBJECT_P(zv) tf_buffer_object_fetch_object(Z_OBJ_P(zv))

// argument info
ZEND_BEGIN_ARG_INFO_EX(arginfo_tf_buffer___construct, 0, 0, 0)
    ZEND_ARG_INFO(0, buffer)
ZEND_END_ARG_INFO()

// methods
static zend_function_entry tf_buffer_methods[] = {
    PHP_ME(TensorFlow_Buffer, __construct, arginfo_tf_buffer___construct, ZEND_ACC_PUBLIC)
    PHP_ME(TensorFlow_Buffer, __toString,  NULL,                          ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void define_tf_buffer_class()
{
    zend_class_entry temp_ce;

    INIT_NS_CLASS_ENTRY(temp_ce, "TensorFlow", "Buffer", tf_buffer_methods);

    ce_TF_Buffer = zend_register_internal_class(&temp_ce);
    ce_TF_Buffer->create_object = tf_buffer_object_create;

    memcpy(&oh_TF_Buffer, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    oh_TF_Buffer.clone_obj = NULL;
    oh_TF_Buffer.free_obj = tf_buffer_object_free;
    oh_TF_Buffer.offset = XtOffsetOf(t_tf_buffer_object, std);
}

zend_object* tf_buffer_object_create(zend_class_entry *ce TSRMLS_DC)
{
    t_tf_buffer_object *intern;

    intern = (t_tf_buffer_object *)ecalloc(1, sizeof(t_tf_buffer_object));
    intern->ptr = tf_buffer_ctor(TSRMLS_C);

    zend_object_std_init(&intern->std, ce TSRMLS_CC);
    object_properties_init(&intern->std, ce);

    intern->std.handlers = &oh_TF_Buffer;

    return &intern->std;
}

static void tf_buffer_object_free(zend_object *object TSRMLS_DC)
{
    t_tf_buffer_object *intern = tf_buffer_object_fetch_object(object);
    tf_buffer_dtor(intern->ptr TSRMLS_CC);
    zend_object_std_dtor(&intern->std TSRMLS_CC);
}

static t_tf_buffer* tf_buffer_ctor(TSRMLS_D)
{
    t_tf_buffer *php_tf_buffer = NULL;
    php_tf_buffer = (t_tf_buffer *)ecalloc(1, sizeof(t_tf_buffer));
    if (php_tf_buffer == NULL) {
        return NULL;
    }

    php_tf_buffer->src = NULL;
    php_tf_buffer->str = NULL;
    php_tf_buffer->ref = 1;

    return php_tf_buffer;
}

// extern void TF_DeleteBuffer(TF_Buffer*);
static void tf_buffer_dtor(t_tf_buffer* tf_buffer TSRMLS_DC)
{
    tf_buffer->ref--;
    if (tf_buffer->ref == 0) {
        if (tf_buffer->str != NULL) {
            zend_string_release(tf_buffer->str);
        }
        TF_DeleteBuffer(tf_buffer->src);
        efree(tf_buffer);
    }
}

// extern TF_Buffer* TF_NewBufferFromString(const void* proto, size_t proto_len);
// extern TF_Buffer* TF_NewBuffer();
static PHP_METHOD(TensorFlow_Buffer, __construct)
{
    // arguments
    zend_string* buffer;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR(buffer)
    ZEND_PARSE_PARAMETERS_END();

    // this
    t_tf_buffer_object* intern;
    t_tf_buffer* php_tf_buffer;

    intern = TF_BUFFER_OBJECT_P(getThis());
    php_tf_buffer = intern->ptr;

    if (ZEND_NUM_ARGS() == 1) {
        php_tf_buffer->src = TF_NewBufferFromString(ZSTR_VAL(buffer), ZSTR_LEN(buffer));
    } else {
        php_tf_buffer->src = TF_NewBuffer();
    }
}

static PHP_METHOD(TensorFlow_Buffer, __toString)
{
    zend_string* result;

    // this
    t_tf_buffer_object* intern;
    t_tf_buffer* php_tf_buffer;
    TF_Buffer* tf_buffer;

    intern = TF_BUFFER_OBJECT_P(getThis());
    php_tf_buffer = intern->ptr;
    tf_buffer = php_tf_buffer->src;


    RETURN_STR(zend_string_init(tf_buffer->data, tf_buffer->length, 0));
}
