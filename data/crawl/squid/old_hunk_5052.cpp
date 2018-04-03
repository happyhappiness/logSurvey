
            if (strcasecmp(digest_request->response, Response)) {
                credentials(Failed);
                return;
            } else {
                const char *useragent = httpHeaderGetStr(&request->header, HDR_USER_AGENT);
