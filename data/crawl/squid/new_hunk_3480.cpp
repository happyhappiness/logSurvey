                    storeAppendPrintf(sentry, "    %12.12s : %8d %3d%%\n",
                                      icp_opcode_str[op],
                                      e->icp.counts[op],
                                      Math::intPercent(e->icp.counts[op], e->stats.pings_acked));
                }

#if USE_HTCP
