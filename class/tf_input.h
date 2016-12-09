// // Represents a specific input of an operation.
// typedef struct TF_Input {
//   TF_Operation* oper;
//   int index;  // The index of the input within oper.
// } TF_Input;

// // In this code:
// //   TF_Output producer = TF_OperationInput(consumer);
// // There is an edge from producer.oper's output (given by
// // producer.index) to consumer.oper's input (given by consumer.index).
// extern TF_Output TF_OperationInput(TF_Input oper_in);
