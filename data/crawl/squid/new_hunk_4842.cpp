            /* We are allowed to do this typecast */
            HttpReply *rep = (HttpReply *) pe->getReply();      // bypass const
            rep->setHeaders(version, HTTP_OK, "Internal marker object", "x-squid-internal/vary", -1, -1, squid_curtime + 100000);
            vary = mem->getReply()->header.getList(HDR_VARY);

            if (vary.size()) {
                /* Again, we own this structure layout */
                ((HttpHeader) pe->getReply()->header).putStr(HDR_VARY, vary.buf());
                vary.clean();
            }

#if X_ACCELERATOR_VARY
            vary = mem->getReply()->header.getList(HDR_X_ACCELERATOR_VARY);

            if (vary.buf()) {
                /* Again, we own this structure layout */
                ((HttpHeader) pe->getReply()->header).putStr(HDR_X_ACCELERATOR_VARY, vary.buf());
                vary.clean();
            }

