         */
        if(!Config.errorDirectory) {
            /* We 'negotiated' this ONLY from the Accept-Language. */
            httpHeaderDelById(&rep->header, HDR_VARY);
            httpHeaderPutStrf(&rep->header, HDR_VARY, "Accept-Language");
        }

        /* add the Content-Language header according to RFC section 14.12 */
        if(err_language) {
            httpHeaderPutStrf(&rep->header, HDR_CONTENT_LANGUAGE, "%s", err_language);
        }
        else
#endif /* USE_ERROR_LOCALES */
        {
            /* default templates are in English */
            /* language is known unless error_directory override used */
            if(!Config.errorDirectory)
                httpHeaderPutStrf(&rep->header, HDR_CONTENT_LANGUAGE, "en");
        }

        httpBodySet(&rep->body, content);