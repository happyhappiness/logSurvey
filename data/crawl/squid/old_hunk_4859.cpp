void
ClientSocketContext::initiateClose()
{
    if (!http || !http->getConn().getRaw()) {
        doClose();
        return;
    }

    if (http->getConn()->body_size_left > 0)  {
        debug(33, 5) ("ClientSocketContext::initiateClose: closing, but first we need to read the rest of the request\n");
        /* XXX We assumes the reply does fit in the TCP transmit window.
         * If not the connection may stall while sending the reply
         * (before reaching here) if the client does not try to read the
                * response while sending the request body. As of yet we have
                * not received any complaints indicating this may be an issue.
                */
        http->getConn()->closing(true);
        clientAbortBody(http->request);
        return;
    }

    doClose();
