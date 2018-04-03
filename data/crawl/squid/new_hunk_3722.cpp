                    storeAppendPrintf(entry, "{%s}", arg);

                for (te = logformat_token_table; te->config != NULL; te++) {
                    if (te->token_type == type) {
                        storeAppendPrintf(entry, "%s", te->config);
                        break;
                    }
