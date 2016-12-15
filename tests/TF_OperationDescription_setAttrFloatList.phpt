--TEST--
TensorFlow\OperationDescription::setAttrFloatList method
--FILE--
<?php
$desc = new TensorFlow\OperationDescription(new TensorFlow\Graph(), "Const", "scalar");
$desc->setAttrFloatList("pass", []);
$desc->setAttrFloatList("pass", [1.0]);
$desc->setAttrFloatList("pass", [1.0, 1.1]);
try {
    $desc->setAttrFloatList("fail", ["string"]);
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), "\n";
}

?>
--EXPECT--
values must be array of float
