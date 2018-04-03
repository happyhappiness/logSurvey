        if (ah != NULL) {
            String name, value;
            if (ah->getXxRecord(name, value)) {
                buf.appendf(SQUIDSTRINGPH ": " SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(name), SQUIDSTRINGPRINT(value));
            }
        }
    }

    buf.append("Encapsulated: ", 14);

    MemBuf httpBuf;

