--TEST--
TensorFlow\Status::CODE_* Constants
--FILE--
<?php
echo TensorFlow\Status::CODE_OK, "\n";
echo TensorFlow\Status::CODE_CANCELLED, "\n";
echo TensorFlow\Status::CODE_UNKNOWN, "\n";
echo TensorFlow\Status::CODE_INVALID_ARGUMENT, "\n";
echo TensorFlow\Status::CODE_DEADLINE_EXCEEDED, "\n";
echo TensorFlow\Status::CODE_NOT_FOUND, "\n";
echo TensorFlow\Status::CODE_ALREADY_EXISTS, "\n";
echo TensorFlow\Status::CODE_PERMISSION_DENIED, "\n";
echo TensorFlow\Status::CODE_RESOURCE_EXHAUSTED, "\n";
echo TensorFlow\Status::CODE_FAILED_PRECONDITION, "\n";
echo TensorFlow\Status::CODE_ABORTED, "\n";
echo TensorFlow\Status::CODE_OUT_OF_RANGE, "\n";
echo TensorFlow\Status::CODE_UNIMPLEMENTED, "\n";
echo TensorFlow\Status::CODE_INTERNAL, "\n";
echo TensorFlow\Status::CODE_UNAVAILABLE, "\n";
echo TensorFlow\Status::CODE_DATA_LOSS, "\n";
echo TensorFlow\Status::CODE_UNAUTHENTICATED, "\n";
?>
--EXPECT--
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
