        handleConnectResponse(len);
}

/* Read from client side and queue it for writing to the server */
void
TunnelStateData::ReadConnectResponseDone(const Comm::ConnectionPointer &, char *buf, size_t len, Comm::Flag errcode, int xerrno, void *data)
