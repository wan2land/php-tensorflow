--TEST--
Example Add
--FILE--
<?php

// function scalarConst(TensorFlow $graph, $n) {
//     $tensor = new TensorFlow\Tensor(TensorFlow\DTYPE_INT32, NULL, $n); // 0 차원은 일반 상수.
//     $desc = new TensorFlow\OperationDescription($graph, "Const", "scalar");
//     $desc->setAttrTensor("value", $tensor, NULL);
//     $desc->setAttrType("dtype", TensorFlow\DTYPE_INT32);
//     return $desc->finishOperation(NULL);
// }

// $graph = new TensorFlow\Graph();

// scalarConst($graph, 20);

?>
--EXPECT--
