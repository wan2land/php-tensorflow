--TEST--
TensorFlow\Buffer::__construct method
--FILE--
<?php
$buffer = new TensorFlow\Buffer();
echo ($buffer->__toString() ?: "(null)"), "\n";
$buffer = new TensorFlow\Buffer("hello tf!!");
echo ($buffer->__toString() ?: "(null)"), "\n";

?>
--EXPECT--
(null)
hello tf!!
