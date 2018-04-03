 class ServerBump;
 }
 #endif
+
 /**
- * Manages a connection to a client.
+ * Legacy Server code managing a connection to a client.
+ *
+ * NP: presents AsyncJob API but does not operate autonomously as a Job.
+ *     So Must() is not safe to use.
+ *
+ * Multiple requests (up to pipeline_prefetch) can be pipelined.
+ * This object is responsible for managing which one is currently being
+ * fulfilled and what happens to the queue if the current one causes the client
+ * connection to be closed early.
  *
- * Multiple requests (up to pipeline_prefetch) can be pipelined. This object is responsible for managing
- * which one is currently being fulfilled and what happens to the queue if the current one
- * causes the client connection to be closed early.
+ * Act as a manager for the client connection and passes data in buffer to a
+ * Parser relevant to the state (message headers vs body) that is being
+ * processed.
  *
- * Act as a manager for the connection and passes data in buffer to the current parser.
- * the parser has ambiguous scope at present due to being made from global functions
- * I believe this object uses the parser to identify boundaries and kick off the
- * actual HTTP request handling objects (ClientSocketContext, ClientHttpRequest, HttpRequest)
+ * Performs HTTP message processing to kick off the actual HTTP request
+ * handling objects (ClientSocketContext, ClientHttpRequest, HttpRequest).
  *
- * If the above can be confirmed accurate we can call this object PipelineManager or similar
+ * Performs SSL-Bump processing for switching between HTTP and HTTPS protocols.
+ *
+ * To terminate a ConnStateData close() the client Comm::Connection it is
+ * managing, or for graceful half-close use the stopReceiving() or
+ * stopSending() methods.
  */
 class ConnStateData : public Server, public HttpControlMsgSink, public RegisteredRunner
 {
