--TEST--
Tensorflow\Dtype::__construct method
--FILE--
<?php
new Tensorflow\Dtype();
for ($i = 0; $i < 22; $i++) {
    try {
        $buffer = new Tensorflow\Dtype($i);
    } catch (\InvalidArgumentException $e) {
        echo $e->getMessage(), "/{$i}\n";
    }
}

?>
--EXPECTF--
Warning: Tensorflow\Dtype::__construct() expects exactly 1 parameter, 0 given in %s on line %d
type must be from 1 to 20/0
type must be from 1 to 20/21
