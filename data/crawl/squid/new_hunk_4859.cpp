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
                * the reply (before reaching here) if the client does not
                * try to read the response while sending the request body.
                * As of yet we have not received any complaints indicating
                * this may be an issue.
                */
                conn->closing(true);
                /*
                 * Trigger the BodyReader abort handler, if necessary,
                 * by destroying it.  It is a refcounted pointer, so
                 * set it to NULL and let the destructor be called when
                 * all references are gone.
                 */
                http->request->body_reader = NULL;	// refcounted
                return;
            }
        }
    }

    doClose();
