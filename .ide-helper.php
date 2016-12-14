<?php
namespace TensorFlow
{
    const VERSION;

    const DTYPE_FLOAT = 1;
    const DTYPE_DOUBLE = 2;
    const DTYPE_INT32 = 3;
    const DTYPE_UINT8 = 4;
    const DTYPE_INT16 = 5;
    const DTYPE_INT8 = 6;
    const DTYPE_STRING = 7;
    const DTYPE_COMPLEX64 = 8;
    const DTYPE_COMPLEX = 8;
    const DTYPE_INT64 = 9;
    const DTYPE_BOOL = 10;
    const DTYPE_QINT8 = 11;
    const DTYPE_QUINT8 = 12;
    const DTYPE_QINT32 = 13;
    const DTYPE_BFLOAT16 = 14;
    const DTYPE_QINT16 = 15;
    const DTYPE_QUINT16 = 16;
    const DTYPE_UINT16 = 17;
    const DTYPE_COMPLEX128 = 18;
    const DTYPE_HALF = 19;
    const DTYPE_RESOURCE = 20;

    class Status
    {
        public function setCode(int $code, string $message = ""): void;
        public function getCode(): int;
        public function getMessage(): string;
    }

    class Buffer
    {
        public function __construct(string $buffer);
        public function __toString(): string;
    }

}