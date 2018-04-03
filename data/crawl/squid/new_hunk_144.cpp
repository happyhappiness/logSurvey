        }

        if (!parsedOk) {
            const bool tooBig =
                hp->parseStatusCode == Http::scRequestHeaderFieldsTooLarge ||
                hp->parseStatusCode == Http::scUriTooLong;
            auto result = csd->abortRequestParsing(
                              tooBig ? "error:request-too-large" : "error:invalid-request");
            // assume that remaining leftovers belong to this bad request
            csd->consumeInput(csd->inBuf.length());
            return result;
        }
    }
