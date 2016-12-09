--TEST--
TensorFlow\Tensor::__construct method
--FILE--
<?php
$tensor = new TensorFlow\Tensor(new TensorFlow\Dtype(TensorFlow\Dtype::FLOAT), [2, 3]);

?>
--EXPECT--
