
#include "tf_status.h"

zend_object* tf_status_object_create(zend_class_entry* ce TSRMLS_DC);
static void tf_status_object_free(zend_object *object TSRMLS_DC);
static php_tf_status* tf_status_ctor(TSRMLS_D);
static void tf_status_dtor(php_tf_status* tf_status TSRMLS_DC);

// class entries
static zend_class_entry *ce_TF_Status = NULL;

static zend_object_handlers oh_TF_Status;

static inline php_tf_status_object* tf_status_object_fetch_object(zend_object *obj) {
    return (php_tf_status_object*)((char *)obj - XtOffsetOf(php_tf_status_object, std));
}
#define TF_STATUS_OBJECT_P(zv) tf_status_object_fetch_object(Z_OBJ_P(zv))

// argument info
ZEND_BEGIN_ARG_INFO_EX(arginfo_setCode, 0, 0, 1)
    ZEND_ARG_INFO(0, code)
    ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

// methods
static zend_function_entry tf_status_methods[] = {
    PHP_ME(Tensorflow_Status, setCode,      arginfo_setCode,    ZEND_ACC_PUBLIC)
    PHP_ME(Tensorflow_Status, getCode,      NULL,           ZEND_ACC_PUBLIC)
    PHP_ME(Tensorflow_Status, getMessage,   NULL,           ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

void define_tf_status_class()
{
    zend_class_entry temp_ce;

    INIT_NS_CLASS_ENTRY(temp_ce, "Tensorflow", "Status", tf_status_methods);

    ce_TF_Status = zend_register_internal_class(&temp_ce);
    ce_TF_Status->create_object = tf_status_object_create;

    #define TF_STATUS_CLASS_CONST(name, value) zend_declare_class_constant_long(ce_TF_Status, name, sizeof(name) - 1, value);

    TF_STATUS_CLASS_CONST("CODE_OK", 0);
    TF_STATUS_CLASS_CONST("CODE_CANCELLED", 1);
    TF_STATUS_CLASS_CONST("CODE_UNKNOWN", 2);
    TF_STATUS_CLASS_CONST("CODE_INVALID_ARGUMENT", 3);
    TF_STATUS_CLASS_CONST("CODE_DEADLINE_EXCEEDED", 4);
    TF_STATUS_CLASS_CONST("CODE_NOT_FOUND", 5);
    TF_STATUS_CLASS_CONST("CODE_ALREADY_EXISTS", 6);
    TF_STATUS_CLASS_CONST("CODE_PERMISSION_DENIED", 7);
    TF_STATUS_CLASS_CONST("CODE_RESOURCE_EXHAUSTED", 8);
    TF_STATUS_CLASS_CONST("CODE_FAILED_PRECONDITION", 9);
    TF_STATUS_CLASS_CONST("CODE_ABORTED", 10);
    TF_STATUS_CLASS_CONST("CODE_OUT_OF_RANGE", 11);
    TF_STATUS_CLASS_CONST("CODE_UNIMPLEMENTED", 12);
    TF_STATUS_CLASS_CONST("CODE_INTERNAL", 13);
    TF_STATUS_CLASS_CONST("CODE_UNAVAILABLE", 14);
    TF_STATUS_CLASS_CONST("CODE_DATA_LOSS", 15);
    TF_STATUS_CLASS_CONST("CODE_UNAUTHENTICATED", 16);

    memcpy(&oh_TF_Status, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    oh_TF_Status.clone_obj = NULL;
    oh_TF_Status.free_obj = tf_status_object_free;
    oh_TF_Status.offset = XtOffsetOf(php_tf_status_object, std);
}

zend_object* tf_status_object_create(zend_class_entry *ce TSRMLS_DC)
{
    php_tf_status_object *intern;

    intern = (php_tf_status_object *)ecalloc(1, sizeof(php_tf_status_object));
    intern->ptr = tf_status_ctor(TSRMLS_C);

    zend_object_std_init(&intern->std, ce TSRMLS_CC);
    object_properties_init(&intern->std, ce);

    intern->std.handlers = &oh_TF_Status;

    return &intern->std;
}

static void tf_status_object_free(zend_object *object TSRMLS_DC)
{
    php_tf_status_object *intern = tf_status_object_fetch_object(object);
    tf_status_dtor(intern->ptr TSRMLS_CC);
    zend_object_std_dtor(&intern->std TSRMLS_CC);
}

static php_tf_status* tf_status_ctor(TSRMLS_D)
{
    php_tf_status *tf_status = NULL;
    tf_status = (php_tf_status *)ecalloc(1, sizeof(php_tf_status));
    if (tf_status == NULL) {
        return NULL;
    }

    tf_status->ptr = TF_NewStatus();
    tf_status->str = NULL;
    tf_status->ref = 1;

    return tf_status;
}

static void tf_status_dtor(php_tf_status* tf_status TSRMLS_DC)
{
    tf_status->ref--;
    if (tf_status->ref == 0) {
        if (tf_status->str != NULL) {
            zend_string_release(tf_status->str);
        }
        TF_DeleteStatus(tf_status->ptr);
        efree(tf_status);
    }
}

// void TF_SetStatus(TF_Status* s, TF_Code code, const char* message);
static PHP_METHOD(Tensorflow_Status, setCode)
{
    // arguments
    int code;
    char* message = NULL;
    size_t message_len;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l|s", &code, &message, &message_len) == FAILURE) {
        RETURN_NULL();
        return;
    }
    // ZEND_PARSE_PARAMETERS_START(1, 2)
    //     Z_PARAM_LONG(code)
    //     Z_PARAM_OPTIONAL
    //     Z_PARAM_STR(message)
    // ZEND_PARSE_PARAMETERS_END();

    // this
    php_tf_status_object* intern;
    php_tf_status* xnode;
    TF_Status* node;

    intern = TF_STATUS_OBJECT_P(getThis());
    xnode = intern->ptr;
    node = xnode->ptr;

    if (message == NULL) {
        TF_SetStatus(node, code, "");
    } else {
        TF_SetStatus(node, code, message);
    }
}

// extern TF_Code TF_GetCode(const TF_Status* s);
static PHP_METHOD(Tensorflow_Status, getCode)
{
    if (ZEND_NUM_ARGS() != 0) {
        WRONG_PARAM_COUNT;
    }

    // this
    php_tf_status_object* intern;
    php_tf_status* xnode;
    TF_Status* node;

    intern = TF_STATUS_OBJECT_P(getThis());
    xnode = intern->ptr;
    node = xnode->ptr;

    RETURN_LONG(TF_GetCode(node));
}


// extern const char* TF_Message(const TF_Status* s);
static PHP_METHOD(Tensorflow_Status, getMessage)
{
    if (ZEND_NUM_ARGS() != 0) {
        WRONG_PARAM_COUNT;
    }

    // this
    php_tf_status_object* intern;
    php_tf_status* xnode;
    TF_Status* node;

    intern = TF_STATUS_OBJECT_P(getThis());
    xnode = intern->ptr;
    node = xnode->ptr;

    RETURN_STRING(TF_Message(node));
}
