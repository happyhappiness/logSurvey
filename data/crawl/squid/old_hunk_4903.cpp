            if (request->auth_user_request->username())
                buf.Printf("X-Client-Username: %s\r\n", request->auth_user_request->username());

    fprintf(stderr, "%s\n", buf.content());

    buf.append(ICAP::crlf, 2); // terminate ICAP header

