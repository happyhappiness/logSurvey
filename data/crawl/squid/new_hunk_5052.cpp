
            if (strcasecmp(digest_request->response, Response)) {
                credentials(Failed);
                digest_request->setDenyMessage("Incorrect password");
                return;
            } else {
                const char *useragent = httpHeaderGetStr(&request->header, HDR_USER_AGENT);
