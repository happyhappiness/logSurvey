        buf.Printf("Proxy-Authorization: " SQUIDSTRINGPH "\r\n", SQUIDSTRINGPRINT(vh));
    }

    buf.Printf("Encapsulated: ");

    MemBuf httpBuf;
