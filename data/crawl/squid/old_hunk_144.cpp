        }

        if (!parsedOk) {
            if (hp->parseStatusCode == Http::scRequestHeaderFieldsTooLarge || hp->parseStatusCode == Http::scUriTooLong)
                return csd->abortRequestParsing("error:request-too-large");

            return csd->abortRequestParsing("error:invalid-request");
        }
    }
