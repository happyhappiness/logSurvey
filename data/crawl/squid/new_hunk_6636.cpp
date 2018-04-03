	}
    }
    storeBuffer(e);
    httpReplyReset(reply);
    /* set standard stuff */
    httpReplySetHeaders(reply, 1.0, HTTP_OK, "Gatewaying",
