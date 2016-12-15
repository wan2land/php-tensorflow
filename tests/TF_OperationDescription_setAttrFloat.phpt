--TEST--
TensorFlow\OperationDescription::setAttrFloat method
--FILE--
<?php
$desc = new TensorFlow\OperationDescription(new TensorFlow\Graph(), "Const", "scalar");
$desc->setAttrFloat("pass", 1.0);
$desc->setAttrFloat("pass", 2.1);
$desc->setAttrFloat("pass", 3.3);
$desc->setAttrFloat("pass", "3.3"); // safe

$desc->setAttrFloat("fail", "string");

?>
--EXPECTF--
Warning: TensorFlow\OperationDescription::setAttrFloat() expects parameter 2 to be float, string given in %s on line %d
