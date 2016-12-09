
#include "tf_graph.h"

// predefine
zend_class_entry *ce_TF_Graph = NULL;
zend_object_handlers oh_TF_Graph;

// methods
zend_object* tf_graph_object_create(zend_class_entry* ce TSRMLS_DC);
static void tf_graph_object_free(zend_object *object TSRMLS_DC);

static PHP_METHOD(TensorFlow_Graph, __construct);
static PHP_METHOD(TensorFlow_Graph, __destruct);

// argument info
// ZEND_BEGIN_ARG_INFO_EX(arginfo_tf_graph_setCode, 0, 0, 1)
//     ZEND_ARG_INFO(0, code)
//     ZEND_ARG_INFO(0, message)
// ZEND_END_ARG_INFO()

// methods
static zend_function_entry tf_graph_methods[] = {
    PHP_ME(TensorFlow_Graph, __construct, NULL,                      ZEND_ACC_PUBLIC)
    PHP_ME(TensorFlow_Graph, __destruct,  NULL,                      ZEND_ACC_PUBLIC)
    PHP_FE_END
};

void define_tf_graph_class()
{
    DEFINE_CLASS(Graph, graph, ce_TF_Graph, oh_TF_Graph)
}

CA_OBJECT_CREATE(graph, t_tf_graph, t_tf_graph_object, oh_TF_Graph)
CA_OBJECT_FREE(graph, t_tf_graph, t_tf_graph_object)

// extern TF_Graph* TF_NewGraph();
static PHP_METHOD(TensorFlow_Graph, __construct)
{
    t_tf_graph_object* intern = TF_GRAPH_P_ZV(getThis());
    t_tf_graph* node = intern->ptr;

    node->src = TF_NewGraph();
}

// extern void TF_DeleteGraph(TF_Graph*);
static PHP_METHOD(TensorFlow_Graph, __destruct)
{
    t_tf_graph_object* intern = TF_GRAPH_P_ZV(getThis());
    t_tf_graph* node = intern->ptr;

    TF_DeleteGraph(node->src);
}

// extern void TF_GraphSetTensorShape(TF_Graph* graph, TF_Output output,
//                                    const int64_t* dims, const int num_dims,
//                                    TF_Status* status);

// // Returns the number of dimensions of the Tensor referenced by `output`
// // in `graph`.
// //
// // If the number of dimensions in the shape is unknown, returns -1.
// //
// // Returns an error into `status` if:
// //   * `output` is not in `graph`.
// extern int TF_GraphGetTensorNumDims(TF_Graph* graph, TF_Output output,
//                                     TF_Status* status);

// // Returns the shape of the Tensor referenced by `output` in `graph`
// // into `dims`. `dims` must be an array large enough to hold `num_dims`
// // entries (e.g., the return value of TF_GraphGetTensorNumDims).
// //
// // If the number of dimensions in the shape is unknown or the shape is
// // a scalar, `dims` will remain untouched. Otherwise, each element of
// // `dims` will be set corresponding to the size of the dimension. An
// // unknown dimension is represented by `-1`.
// //
// // Returns an error into `status` if:
// //   * `output` is not in `graph`.
// //   * `num_dims` does not match the actual number of dimensions.
// extern void TF_GraphGetTensorShape(TF_Graph* graph, TF_Output output,
//                                    int64_t* dims, int num_dims,
//                                    TF_Status* status);

// // Iterate through the operations of a graph.  To use:
// // size_t pos = 0;
// // TF_Operation* oper;
// // while ((oper = TF_GraphNextOperation(graph, &pos)) != nullptr) {
// //   DoSomethingWithOperation(oper);
// // }
// extern TF_Operation* TF_GraphNextOperation(TF_Graph* graph, size_t* pos);

// // Write out a serialized representation of `graph` (as a GraphDef protocol
// // message) to `output_graph_def` (allocated by TF_NewBuffer()).
// //
// // May fail on very large graphs in the future.
// extern void TF_GraphToGraphDef(TF_Graph* graph, TF_Buffer* output_graph_def,
//                                TF_Status* status);
