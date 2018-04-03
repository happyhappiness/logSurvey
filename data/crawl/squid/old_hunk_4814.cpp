
            if (vary.size()) {
                /* Again, we own this structure layout */
                ((HttpHeader) pe->getReply()->header).putStr(HDR_VARY, vary.buf());
                vary.clean();
            }

