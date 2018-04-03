                comma = 1;
            }

            if (flags & WCCP2_SERVICE_SOURCE_PORT_HASH) {
                storeAppendPrintf(e, "%ssource_port_hash", comma ? "," : "");
                comma = 1;
            }