
/**
 * Badly named.
 * This is in fact the processing context for a single HTTP transaction.
 *
 * A context lifetime extends from directly after a request has been parsed
 * off the client connection buffer, until the last byte of both request
 * and reply payload (if any) have been written.
 *
 * (NOTE: it is not certain yet if an early reply to a POST/PUT is sent by
 * the server whether the context will remain in the pipeline until its
 * request payload has finished being read. It is supposed to, but may not)
 *
 * Contexts self-register with the Pipeline being managed by the Server
 * for the connection on which the request was received.
 *
 * When HTTP/1 pipeline is operating there may be multiple transactions using
 * the clientConnection. Only the back() context may read from the connection,
 * and only the front() context may write to it. A context which needs to read
 * or write to the connection but does not meet those criteria must be shifted
 * to the deferred state.
 *
 * When a context is completed the finished() method needs to be called which
 * will perform all cleanup and deregistration operations. If the reason for
 * finishing is an error, then notifyIoError() needs to be called prior to
 * the finished() method.
 * The caller should follow finished() with a call to ConnStateData::kick()
 * to resume processing of other transactions or I/O on the connection.
 *
 * Alternatively the initiateClose() method can be called to terminate the
 * whole client connection and all other pending contexts.
 *
 * The socket level management is done by a Server which owns us.
 * The scope of this objects control over a socket consists of the data
 * buffer received from the Server with an initially unknown length.
 * When that length is known it sets the end boundary of our access to the
 * buffer.
 *
 * The individual processing actions are done by other Jobs which we
 * kick off as needed.
 *
 * XXX: If an async call ends the ClientHttpRequest job, ClientSocketContext
 * (and ConnStateData) may not know about it, leading to segfaults and
 * assertions. This is difficult to fix
 * because ClientHttpRequest lacks a good way to communicate its ongoing
 * destruction back to the ClientSocketContext which pretends to "own" *http.
 */
