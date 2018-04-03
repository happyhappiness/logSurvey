    clientConnection->close();
}

/** Called to initiate (and possibly complete) closing of the context.
 * The underlying socket may be already closed */
void
ClientSocketContext::initiateClose(const char *reason)
{
    debugs(33, 5, HERE << "initiateClose: closing for " << reason);

    if (http != NULL) {
        ConnStateData * conn = http->getConn();

        if (conn != NULL) {
            if (const int64_t expecting = conn->mayNeedToReadMoreBody()) {
                debugs(33, 5, HERE << "ClientSocketContext::initiateClose: " <<
                       "closing, but first " << conn << " needs to read " <<
                       expecting << " request body bytes with " <<
                       conn->in.notYetUsed << " notYetUsed");

                if (conn->closing()) {
                    debugs(33, 2, HERE << "avoiding double-closing " << conn);
                    return;
                }

                /*
                * XXX We assume the reply fits in the TCP transmit
                * window.  If not the connection may stall while sending
                * the reply (before reaching here) if the client does not
                * try to read the response while sending the request body.
                * As of yet we have not received any complaints indicating
                * this may be an issue.
                */
                conn->startClosing(reason);

                return;
            }
        }
    }

    doClose();
}

void
