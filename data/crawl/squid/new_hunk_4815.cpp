
            if (vary.buf()) {
                /* Again, we own this structure layout */
                rep->header.putStr(HDR_X_ACCELERATOR_VARY, vary.buf());
                vary.clean();
            }
