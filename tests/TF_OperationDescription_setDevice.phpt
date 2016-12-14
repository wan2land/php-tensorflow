--TEST--
TensorFlow\OperationDescription::setDevice method
--FILE--
<?php
$desc = new TensorFlow\OperationDescription(new TensorFlow\Graph(), "Const", "scalar");
$desc->setDevice("device");

?>
--EXPECT--
