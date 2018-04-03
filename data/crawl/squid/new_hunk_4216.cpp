         * X-CACHE-MISS entry should tell us who.
         */
        httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%s %d", name, xerrno);

        /* add the Content-Language header according to RFC section 14.21 */
        if(err_language) {
            httpHeaderPutStrf(&rep->header, HDR_CONTENT_LANGUAGE, "%s", err_language);
            /* TODO: do we need to modify Vary: header as well? */
        }
        else {
            /* default templates are in English */
            httpHeaderPutStrf(&rep->header, HDR_CONTENT_LANGUAGE, "en");
        }

        httpBodySet(&rep->body, content);
        /* do not memBufClean() or delete the content, it was absorbed by httpBody */
    }
