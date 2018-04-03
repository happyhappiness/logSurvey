            buf.Printf("X-Client-IP: %s\r\n", inet_ntoa(request->client_addr));

    if (TheICAPConfig.send_client_username && request)
        if (request->auth_user_request)
            if (request->auth_user_request->username())
                buf.Printf("X-Client-Username: %s\r\n", request->auth_user_request->username());

    // fprintf(stderr, "%s\n", buf.content());

