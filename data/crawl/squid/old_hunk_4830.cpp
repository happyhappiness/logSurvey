                digest_request->setDenyMessage("Incorrect password");
                return;
            } else {
                const char *useragent = httpHeaderGetStr(&request->header, HDR_USER_AGENT);

                static struct IN_ADDR last_broken_addr;
                static int seen_broken_client = 0;
