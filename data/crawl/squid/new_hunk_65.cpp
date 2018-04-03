            auto result = csd->abortRequestParsing(
                              tooBig ? "error:request-too-large" : "error:invalid-request");
            // assume that remaining leftovers belong to this bad request
            if (!csd->inBuf.isEmpty())
                csd->consumeInput(csd->inBuf.length());
            return result;
        }
    }
