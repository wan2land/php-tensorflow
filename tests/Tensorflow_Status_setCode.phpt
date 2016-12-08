--TEST--
Tensorflow\Status::setCode method
--FILE--
<?php
$status = new Tensorflow\Status;
$status->setCode(10, "hello tf!");
echo $status->getCode(), "\n";
echo $status->getMessage(), "\n";
?>
--EXPECT--
10
hello tf!
