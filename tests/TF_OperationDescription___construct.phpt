--TEST--
TensorFlow\OperationDescription::__construct method
--FILE--
<?php
$desc = new TensorFlow\OperationDescription(new TensorFlow\Graph(), "Const", "scalar");
?>
--EXPECT--
