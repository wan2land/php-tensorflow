// // --------------------------------------------------------------------------
// // TF_SessionOptions holds options that can be passed during session creation.
// typedef struct TF_SessionOptions TF_SessionOptions;

// // Return a new options object.
// extern TF_SessionOptions* TF_NewSessionOptions();

// // Set the target in TF_SessionOptions.options.
// // target can be empty, a single entry, or a comma separated list of entries.
// // Each entry is in one of the following formats :
// // "local"
// // ip:port
// // host:port
// extern void TF_SetTarget(TF_SessionOptions* options, const char* target);

// // Set the config in TF_SessionOptions.options.
// // config should be a serialized tensorflow.ConfigProto proto.
// // If config was not parsed successfully as a ConfigProto, record the
// // error information in *status.
// extern void TF_SetConfig(TF_SessionOptions* options, const void* proto,
//                          size_t proto_len, TF_Status* status);

// // Destroy an options object.
// extern void TF_DeleteSessionOptions(TF_SessionOptions*);
