
    stopSending(false);

    // see stopReceiving() for reasons it cannot NULLify virgin there

    if (virgin != NULL) {
        if (!state.doneReceiving)
            virgin->sendSinkAbort();
        else
            virgin->sink = NULL;

        virgin = NULL; // refcounted
    }

    if (self != NULL) {
        Pointer s = self;
        self = NULL;
        ICAPNoteXactionDone(s);
        /* this object may be destroyed when 's' is cleared */
    }
}

void ICAPModXact::makeRequestHeaders(MemBuf &buf)
