<?php

namespace Tensorflow
{
    const VERSION = null;

    class Status
    {
        public function setCode(int $code, string $message = ""): void {}
        public function getCode(): int {}
        public function getMessage(): string {}
    }
}
