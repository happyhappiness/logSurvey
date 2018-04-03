class ServerBump;
}
#endif
/**
 * Manages a connection to a client.
 *
 * Multiple requests (up to pipeline_prefetch) can be pipelined. This object is responsible for managing
 * which one is currently being fulfilled and what happens to the queue if the current one
 * causes the client connection to be closed early.
 *
 * Act as a manager for the connection and passes data in buffer to the current parser.
 * the parser has ambiguous scope at present due to being made from global functions
 * I believe this object uses the parser to identify boundaries and kick off the
 * actual HTTP request handling objects (ClientSocketContext, ClientHttpRequest, HttpRequest)
 *
 * If the above can be confirmed accurate we can call this object PipelineManager or similar
 */
class ConnStateData : public Server, public HttpControlMsgSink, public RegisteredRunner
{
