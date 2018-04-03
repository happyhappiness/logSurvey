        buf.Printf("Proxy-Authorization: " SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(vh));
    }

    const HttpRequest *request = &virginRequest();

    // share the cross-transactional database records if needed
    if (Adaptation::Config::masterx_shared_name) {
        Adaptation::History::Pointer ah = request->adaptHistory();
        if (ah != NULL) {
            String name, value;
            if (ah->getXxRecord(name, value)) {
                buf.Printf(SQUIDSTRINGPH ": " SQUIDSTRINGPH "\r\n",  
                    SQUIDSTRINGPRINT(name), SQUIDSTRINGPRINT(value));
            }
        }
    }
    

    buf.Printf("Encapsulated: ");

    MemBuf httpBuf;
