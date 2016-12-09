#ifndef PHP_TENSORFLOW_SESSION_H
#define PHP_TENSORFLOW_SESSION_H

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_exceptions.h>

#include "tensorflow/c/c_api.h" // use this only

typedef struct _t_tf_session {
    TF_Session* src;
    zend_string* str;
    int ref;
} t_tf_session;

typedef struct _t_tf_session_object {
    zend_object std;
    t_tf_session* ptr;
} t_tf_session_object;

static PHP_METHOD(TensorFlow_Session __construct);
// static PHP_METHOD(TensorFlow_Session getType);
// static PHP_METHOD(TensorFlow_Session getDims);
// static PHP_METHOD(TensorFlow_Session getByteSize);
// static PHP_METHOD(TensorFlow_Session getData);

void define_tf_session_class();

#endif  /* PHP_TENSORFLOW_SESSION_H */


// // --------------------------------------------------------------------------
// // API for driving Graph execution.

// typedef struct TF_Session TF_Session;

// // Return a new execution session with the associated graph, or NULL on error.
// //
// // *graph must be a valid graph (not deleted or nullptr).  This function will
// // prevent the graph from being deleted until TF_DeleteSession() is called.
// // Does not take ownership of opts.
// extern TF_Session* TF_NewSession(TF_Graph* graph, const TF_SessionOptions* opts,
//                                  TF_Status* status);

// // Close a session.
// //
// // Contacts any other processes associated with the session, if applicable.
// // May not be called after TF_DeleteSession().
// extern void TF_CloseSession(TF_Session*, TF_Status* status);

// // Destroy a session object.
// //
// // Even if error information is recorded in *status, this call discards all
// // local resources associated with the session.  The session may not be used
// // during or after this call (and the session drops its reference to the
// // corresponding graph).
// extern void TF_DeleteSession(TF_Session*, TF_Status* status);

// // Run the graph associated with the session starting with the supplied inputs
// // (inputs[0,ninputs-1] with corresponding values in input_values[0,ninputs-1]).
// //
// // Any NULL and non-NULL value combinations for (`run_options`,
// // `run_metadata`) are valid.
// //
// //    - `run_options` may be NULL, in which case it will be ignored; or
// //      non-NULL, in which case it must point to a `TF_Buffer` containing the
// //      serialized representation of a `RunOptions` protocol buffer.
// //    - `run_metadata` may be NULL, in which case it will be ignored; or
// //      non-NULL, in which case it must point to an empty, freshly allocated
// //      `TF_Buffer` that may be updated to contain the serialized representation
// //      of a `RunMetadata` protocol buffer.
// //
// // The caller retains ownership of `input_values` (which can be deleted using
// // TF_DeleteTensor). The caller also retains ownership of `run_options` and/or
// // `run_metadata` (when not NULL) and should manually call TF_DeleteBuffer on
// // them.
// //
// // On success, the tensors corresponding to outputs[0,noutputs-1] are placed in
// // output_values[]. Ownership of the elements of output_values[] is transferred
// // to the caller, which must eventually call TF_DeleteTensor on them.
// //
// // On failure, output_values[] contains NULLs.
// extern void TF_SessionRun(TF_Session* session,
//                           // RunOptions
//                           const TF_Buffer* run_options,
//                           // Input tensors
//                           const TF_Output* inputs,
//                           TF_Tensor* const* input_values, int ninputs,
//                           // Output tensors
//                           const TF_Output* outputs, TF_Tensor** output_values,
//                           int noutputs,
//                           // Target operations
//                           const TF_Operation* const* target_opers, int ntargets,
//                           // RunMetadata
//                           TF_Buffer* run_metadata,
//                           // Output status
//                           TF_Status*);

// // Set up the graph with the intended feeds (inputs) and fetches (outputs) for a
// // sequence of partial run calls.
// //
// // On success, returns a handle that is used for subsequent PRun calls.
// //
// // On failure, out_status contains a tensorflow::Status with an error
// // message.
// // NOTE: This is EXPERIMENTAL and subject to change.
// extern void TF_SessionPRunSetup(TF_Session*,
//                                 // Input names
//                                 const TF_Output* inputs, int ninputs,
//                                 // Output names
//                                 const TF_Output* outputs, int noutputs,
//                                 // Target operations
//                                 const TF_Operation* const* target_opers,
//                                 int ntargets,
//                                 // Output handle
//                                 const char** handle,
//                                 // Output status
//                                 TF_Status*);

// // Continue to run the graph with additional feeds and fetches. The
// // execution state is uniquely identified by the handle.
// // NOTE: This is EXPERIMENTAL and subject to change.
// extern void TF_SessionPRun(TF_Session*, const char* handle,
//                            // Input tensors
//                            const TF_Output* inputs,
//                            TF_Tensor* const* input_values, int ninputs,
//                            // Output tensors
//                            const TF_Output* outputs, TF_Tensor** output_values,
//                            int noutputs,
//                            // Target operations
//                            const TF_Operation* const* target_opers,
//                            int ntargets,
//                            // Output status
//                            TF_Status*);
