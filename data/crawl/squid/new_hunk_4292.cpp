            hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());
    }
    /** If set to DELETE - do not copy through. */
    strFwd.clean();

    /* append Host if not there already */