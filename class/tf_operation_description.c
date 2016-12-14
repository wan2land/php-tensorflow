
#include "tf_operation_description.h"

// predefine
zend_class_entry *ce_TF_OperationDescription = NULL;
zend_object_handlers oh_TF_OperationDescription;

// methods
static PHP_METHOD(TensorFlow_OperationDescription, __construct);
static PHP_METHOD(TensorFlow_OperationDescription, __destruct);
static PHP_METHOD(TensorFlow_OperationDescription, setDevice);

// argument info
ZEND_BEGIN_ARG_INFO_EX(arginfo_tf_operation_description___construct, 0, 0, 3)
    ZEND_ARG_INFO(0, graph)
    ZEND_ARG_INFO(0, operatorType)
    ZEND_ARG_INFO(0, operatorName)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO_EX(arginfo_tf_operation_description_setDevice, 0, 0, 1)
    ZEND_ARG_INFO(0, device)
ZEND_END_ARG_INFO()

// methods
static zend_function_entry tf_operation_description_methods[] = {
    PHP_ME(TensorFlow_OperationDescription, __construct,
                    arginfo_tf_operation_description___construct, ZEND_ACC_PUBLIC)
    PHP_ME(TensorFlow_OperationDescription, __destruct, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(TensorFlow_OperationDescription, setDevice,
                    arginfo_tf_operation_description_setDevice, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

CA_OBJECT_CREATE(operation_description, t_tf_operation_description, t_tf_operation_description_object, oh_TF_OperationDescription)
CA_OBJECT_FREE(operation_description, t_tf_operation_description, t_tf_operation_description_object)

void define_tf_operation_description_class()
{
    DEFINE_CLASS(OperationDescription, operation_description, ce_TF_OperationDescription, oh_TF_OperationDescription)
}

// extern TF_OperationDescription* TF_NewOperation(TF_Graph* graph,
//         const char* op_type, const char* oper_name);
static PHP_METHOD(TensorFlow_OperationDescription, __construct)
{
    zval *graph;
    zend_string *operatorType;
    zend_string *operatorName;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS_EX(graph, ce_TF_Graph, 0, 1) // last 1 is call by ref.
        Z_PARAM_STR(operatorType)
        Z_PARAM_STR(operatorName)
    ZEND_PARSE_PARAMETERS_END();

    // php_printf("optype : %s\n", operatorType->val);
    // php_printf("opname : %s\n", operatorName->val);

    t_tf_operation_description_object* intern = TF_OPERATION_DESCRIPTION_P_ZV(getThis());
    t_tf_operation_description* node = intern->ptr;

    node->src = TF_NewOperation(
        TF_GRAPH_P_ZV(graph)->ptr->src,
        operatorType->val,
        operatorName->val
    );
}

static PHP_METHOD(TensorFlow_OperationDescription, __destruct)
{
    t_tf_operation_description_object* intern = TF_OPERATION_DESCRIPTION_P_ZV(getThis());
    t_tf_operation_description* node = intern->ptr;
    // ? (node->src);
}

// extern void TF_SetDevice(TF_OperationDescription* desc, const char* device);
static PHP_METHOD(TensorFlow_OperationDescription, setDevice)
{
    zend_string *device;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(device)
    ZEND_PARSE_PARAMETERS_END();

    // php_printf("device : %s\n", device->val);

    t_tf_operation_description_object* intern = TF_OPERATION_DESCRIPTION_P_ZV(getThis());
    t_tf_operation_description* node = intern->ptr;

    TF_SetDevice(node->src, device->val);
}
