--TEST--
TensorFlow\OperationDescription::setAttrInt method
--FILE--
<?php
$desc = new TensorFlow\OperationDescription(new TensorFlow\Graph(), "Const", "scalar");
$desc->setAttrInt("pass", 1);
$desc->setAttrInt("pass", 2);
$desc->setAttrInt("pass", 3);
$desc->setAttrInt("pass", "1.1");

$desc->setAttrInt(new stdClass);

?>
--EXPECTF--
Warning: TensorFlow\OperationDescription::setAttrInt() expects exactly 2 parameters, 1 given in %s on line %d
