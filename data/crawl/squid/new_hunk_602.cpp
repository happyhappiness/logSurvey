                    }
                    request->flags.mustKeepalive = true;
                    if (!request->flags.accelerated && !request->flags.intercepted) {
                        httpHeaderPutStrf(hdr, Http::HdrType::PROXY_SUPPORT, "Session-Based-Authentication");
                        /*
                          We send "Connection: Proxy-Support" header to mark
                          Proxy-Support as a hop-by-hop header for intermediaries that do not
                          understand the semantics of this header. The RFC should have included
                          this recommendation.
                        */
                        httpHeaderPutStrf(hdr, Http::HdrType::CONNECTION, "Proxy-support");
                    }
                    break;
                }