// // --------------------------------------------------------------------------
// // The new graph construction API, still under development.

// // Represents a computation graph.  Graphs may be shared between sessions.
// // Graphs are thread-safe when used as directed below.
// typedef struct TF_Graph TF_Graph;

// // Return a new graph object.
// extern TF_Graph* TF_NewGraph();

// // Destroy an options object.  Graph will be deleted once no more
// // TFSession's are referencing it.
// extern void TF_DeleteGraph(TF_Graph*);

// // Sets the shape of the Tensor referenced by `output` in `graph` to
// // the shape described by `dims` and `num_dims`.
// //
// // If the number of dimensions is unknown, `num_dims` must be
// // set to -1 and dims can be null. If a dimension is unknown,
// // the corresponding entry in the `dims` array must be -1.
// //
// // This does not overwrite the existing shape associated with `output`,
// // but merges the input shape with the existing shape.  For example,
// // setting a shape of [-1, 2] with an existing shape [2, -1] would set
// // a final shape of [2, 2] based on shape merging semantics.
// //
// // Returns an error into `status` if:
// //   * `output` is not in `graph`.
// //   * An invalid shape is being set (e.g., the shape being set
// //     is incompatible with the existing shape).
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

