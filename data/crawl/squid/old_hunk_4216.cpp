         * X-CACHE-MISS entry should tell us who.
         */
        httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%s %d", name, xerrno);
        httpBodySet(&rep->body, content);
        /* do not memBufClean() or delete the content, it was absorbed by httpBody */
    }
