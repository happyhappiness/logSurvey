    if (!TheICAPConfig.reuse_connections)
        buf.Printf("Connection: close\r\n");

    buf.Printf("Encapsulated: ");

    MemBuf httpBuf;
