--TEST--
Tensorflow\Buffer::__construct method
--FILE--
<?php
$buffer = new Tensorflow\Buffer();
echo ($buffer->__toString() ?: "(null)"), "\n";
$buffer = new Tensorflow\Buffer("hello tf!!");
echo ($buffer->__toString() ?: "(null)"), "\n";

?>
--EXPECT--
(null)
hello tf!!
