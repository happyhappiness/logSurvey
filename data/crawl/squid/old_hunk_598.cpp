                digest_request->setDenyMessage("Incorrect password");
                return;
            } else {
                const char *useragent = request->header.getStr(HDR_USER_AGENT);

                static Ip::Address last_broken_addr;
                static int seen_broken_client = 0;
