TensorFlow PHP Extension
========================

use `tensorflow` `0.12.0-rc0` c api.

## Requirements

- [bazel](https://www.bazel.build/versions/master/docs/install.html)
- Environment to build TensorFlow from source code
  ([Linux](https://www.tensorflow.org/versions/master/get_started/os_setup.html#prepare-environment-for-linux)
  or [Mac OS
  X](https://www.tensorflow.org/versions/master/get_started/os_setup.html#prepare-environment-for-mac-os-x)).
  If you'd like to skip reading those details and do not care about GPU
  support, try the following:

  ```sh
  # On Linux
  sudo apt-get install python swig python-numpy

  # On Mac OS X with homebrew
  brew install swig
  ```

## Installation

1. Download and Build the TensorFlow by Git Submodule.

   ```sh
   git submodule update --init --recursive
   cd lib/tensorflow
   ./configure
   bazel build -c opt //tensorflow:libtensorflow.so
   cp bazel-bin/tensorflow/libtensorflow.so /usr/local/lib
   ```

2. Build the PHP Extension

   ```sh
   phpize
   ./configure
   make install
   ```

## Contributions

This API has been built on top of the [C API](https://www.tensorflow.org/code/tensorflow/c/c_api.h),
which is intended for building language bindings for TensorFlow functionality.
However, this is far from complete. Contributions are welcome.

 - do not edit `README.md` directly. edit `README.ok.md`. use
   [is your README ok](https://github.com/wan2land/is-your-readme-ok) that is preprocessor of Markdown.

## Documents

Current useable stuffs.

```php
<?php
namespace TensorFlow
{
    // extern const char* TF_Version();
    const VERSION;

    // typedef enum { ... } TF_DataType
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

    // typedef struct TF_Status TF_Status;
    class Status
    {
        // typedef enum { ... } TF_Code;
        const CODE_OK = 0;
        const CODE_CANCELLED = 1;
        const CODE_UNKNOWN = 2;
        const CODE_INVALID_ARGUMENT = 3;
        const CODE_DEADLINE_EXCEEDED = 4;
        const CODE_NOT_FOUND = 5;
        const CODE_ALREADY_EXISTS = 6;
        const CODE_PERMISSION_DENIED = 7 ;
        const CODE_RESOURCE_EXHAUSTED = 8;
        const CODE_FAILED_PRECONDITION = 9;
        const CODE_ABORTED = 10;
        const CODE_OUT_OF_RANGE = 11;
        const CODE_UNIMPLEMENTED = 12;
        const CODE_INTERNAL = 13;
        const CODE_UNAVAILABLE = 14;
        const CODE_DATA_LOSS = 15;
        const CODE_UNAUTHENTICATED = 16;

        // extern TF_Status* TF_NewStatus();
        public function __construct();

        // extern void TF_DeleteStatus(TF_Status*);
        public function __destruct();

        // extern void TF_SetStatus(TF_Status* s, TF_Code code, const char* msg);
        public function setCode(int $code, string $message = ""): void;

        // extern TF_Code TF_GetCode(const TF_Status* s);
        public function getCode(): int;

        // extern const char* TF_Message(const TF_Status* s);
        public function getMessage(): string;
    }

    /*
     * typedef struct {
     *   const void* data;
     *   size_t length;
     *   void (*data_deallocator)(void* data, size_t length);
     * } TF_Buffer;
     */
    class Buffer
    {
        // extern TF_Buffer* TF_NewBufferFromString(const void* proto, size_t proto_len);
        // extern TF_Buffer* TF_NewBuffer();
        public function __construct(string $buffer = null);

        // extern void TF_DeleteBuffer(TF_Buffer*);
        public function __destruct();

        // extern TF_Buffer TF_GetBuffer(TF_Buffer* buffer);
        // return TF_GetBuffer( ... ).data
        public function __toString(): string;
    }

    // typedef struct TF_Tensor TF_Tensor;
    class Tensor
    {
        // extern TF_Tensor* TF_AllocateTensor(TF_DataType, const int64_t* dims,
        //                                     int num_dims, size_t len);
        public function __construct(int $dtype, array $dims = null);

        // extern void TF_DeleteTensor(TF_Tensor*);
        public function __destruct();

        // extern TF_DataType TF_TensorType(const TF_Tensor*);
        public function getDtype(): int;
    }

    // typedef struct TF_SessionOptions TF_SessionOptions;
    class SessionOptions
    {
        // extern TF_SessionOptions* TF_NewSessionOptions();
        public function __construct();

        // extern void TF_DeleteSessionOptions(TF_SessionOptions*);
        public function __destruct();

        /**
         * extern void TF_SetTarget(TF_SessionOptions* options, const char* target);
         * @param string $target "local", ip:port or host:port
         */
        public function setTarget(string $target);
    }

    // typedef struct TF_Graph TF_Graph;
    class Graph
    {
        /**
         * extern TF_Graph* TF_NewGraph();
         */
        public function __construct();

        /**
         * extern void TF_DeleteGraph(TF_Graph*);
         */
        public function __destruct();
    }

    // typedef struct TF_OperationDescription TF_OperationDescription;
    class OperationDescription
    {
        /**
         * extern TF_OperationDescription* TF_NewOperation(TF_Graph* graph,
         *                                                 const char* op_type,
         *                                                 const char* oper_name);
         *
         * @param Graph $graph
         * @param string $operationType "Const"
         * @param string $operationName
         */
        public function __construct(Graph $graph, string $operationType, string $operationName);

        /**
         * extern void TF_SetDevice(TF_OperationDescription* desc, const char* device);
         */
        public function setDevice(string $device);
    }
}
```

## Reference

- [TensorFlow Go API](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/go)

## Todo

- [Operator Overloading](https://github.com/php/pecl-php-operator)
