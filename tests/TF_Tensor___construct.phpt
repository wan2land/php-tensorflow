--TEST--
TensorFlow\Tensor::__construct method
--FILE--
<?php
for ($i = 0; $i < 22; $i++) {
    try {
        $tensor = new TensorFlow\Tensor($i, [2, 3]);
    } catch (\InvalidArgumentException $e) {
        echo $e->getMessage(), "/{$i}\n";
    }
}
$tensor = new TensorFlow\Tensor(TensorFlow\DTYPE_UINT16, []); // empty array safe
$tensor = new TensorFlow\Tensor(TensorFlow\DTYPE_UINT16, NULL); // null safe

?>
--EXPECT--
dtype must be from 1 to 20/0
dtype must be from 1 to 20/21
