            /* We are allowed to do this typecast */
            HttpReply *rep = (HttpReply *) pe->getReply();      // bypass const
            rep->setHeaders(version, HTTP_OK, "Internal marker object", "x-squid-internal/vary", -1, -1, squid_curtime + 100000);
            vary = httpHeaderGetList(&mem->getReply()->header, HDR_VARY);

            if (vary.size()) {
                /* Again, we own this structure layout */
                httpHeaderPutStr((HttpHeader *)&pe->getReply()->header, HDR_VARY, vary.buf());
                vary.clean();
            }

#if X_ACCELERATOR_VARY
            vary = httpHeaderGetList(&mem->getReply()->header, HDR_X_ACCELERATOR_VARY);

            if (vary.buf()) {
                /* Again, we own this structure layout */
                httpHeaderPutStr((HttpHeader *)&pe->getReply()->header, HDR_X_ACCELERATOR_VARY, vary.buf());
                vary.clean();
            }

