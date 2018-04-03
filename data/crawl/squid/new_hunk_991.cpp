{
    static MemBuf buf;
    buf.reset();
    buf.appendf(" [request->requestId %u]", request->requestId);
    buf.terminate();
    return buf.content();
}
