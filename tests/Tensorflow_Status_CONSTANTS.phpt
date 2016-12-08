--TEST--
Tensorflow\Status::CODE_* Constants
--FILE--
<?php
echo Tensorflow\Status::CODE_OK, "\n";
echo Tensorflow\Status::CODE_CANCELLED, "\n";
echo Tensorflow\Status::CODE_UNKNOWN, "\n";
echo Tensorflow\Status::CODE_INVALID_ARGUMENT, "\n";
echo Tensorflow\Status::CODE_DEADLINE_EXCEEDED, "\n";
echo Tensorflow\Status::CODE_NOT_FOUND, "\n";
echo Tensorflow\Status::CODE_ALREADY_EXISTS, "\n";
echo Tensorflow\Status::CODE_PERMISSION_DENIED, "\n";
echo Tensorflow\Status::CODE_RESOURCE_EXHAUSTED, "\n";
echo Tensorflow\Status::CODE_FAILED_PRECONDITION, "\n";
echo Tensorflow\Status::CODE_ABORTED, "\n";
echo Tensorflow\Status::CODE_OUT_OF_RANGE, "\n";
echo Tensorflow\Status::CODE_UNIMPLEMENTED, "\n";
echo Tensorflow\Status::CODE_INTERNAL, "\n";
echo Tensorflow\Status::CODE_UNAVAILABLE, "\n";
echo Tensorflow\Status::CODE_DATA_LOSS, "\n";
echo Tensorflow\Status::CODE_UNAUTHENTICATED, "\n";
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
