    input.reset();

    // RFC 2616 : future version full-request
    input.append("GET / HTTP/10.12\r\n", 18);
    //printf("TEST: '%s'\n",input.content());
    output.reset(input.content(), input.contentSize());
