--TEST--
TensorFlow\OperationDescription::setAttrIntList method
--FILE--
<?php
$desc = new TensorFlow\OperationDescription(new TensorFlow\Graph(), "Const", "scalar");
$desc->setAttrIntList("pass", []);
$desc->setAttrIntList("pass", [1]);
$desc->setAttrIntList("pass", [1, 2]);
try {
    $desc->setAttrIntList("fail", ["string"]);
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), "\n";
}

?>
--EXPECT--
values must be array of integer
