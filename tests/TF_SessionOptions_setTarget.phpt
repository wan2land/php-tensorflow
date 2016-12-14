--TEST--
TensorFlow\SessionOptions::setTarget method
--FILE--
<?php
$sessionOptions = new TensorFlow\SessionOptions();
$sessionOptions->setTarget("local");

?>
--EXPECT--
