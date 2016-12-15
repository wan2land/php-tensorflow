--TEST--
TensorFlow\OperationDescription::setAttrType method
--FILE--
<?php
$desc = new TensorFlow\OperationDescription(new TensorFlow\Graph(), "Const", "scalar");
$desc->setAttrType("pass", 1);
$desc->setAttrType("pass", 20);
try {
    $desc->setAttrType("fail", 0);
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), "\n";
}
try {
    $desc->setAttrType("fail", 21);
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), "\n";
}

?>
--EXPECT--
dtype must be from 1 to 20
dtype must be from 1 to 20
