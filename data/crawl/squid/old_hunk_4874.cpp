    /* - IP stuff */
    str.Printf("ClientIP: %s\r\n", inet_ntoa(err->src_addr));

    if (err->host) {
        str.Printf("ServerIP: %s\r\n", err->host);
    }

    str.Printf("\r\n");
