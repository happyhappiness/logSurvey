}

void
ClientSocketContext::initiateClose()
{
    if (http != NULL) {
        ConnStateData::Pointer conn = http->getConn();

        if (conn != NULL) {
            if (conn->bodySizeLeft() > 0) {
                debug(33, 5) ("ClientSocketContext::initiateClose: closing, but first we need to read the rest of the request\n");
                /*
                * XXX We assume the reply fits in the TCP transmit
                * window.  If not the connection may stall while sending
