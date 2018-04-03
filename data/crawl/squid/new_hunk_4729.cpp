        virginSendClaim.protectAll();
    }

    if (TheICAPConfig.send_client_ip && request)
        if (request->client_addr.s_addr != any_addr.s_addr &&
            request->client_addr.s_addr != no_addr.s_addr)
            buf.Printf("X-Client-IP: %s\r\n", inet_ntoa(request->client_addr));

    if (TheICAPConfig.send_client_username && request)
        if (request->auth_user_request)
            if (request->auth_user_request->username())
                buf.Printf("X-Client-Username: %s\r\n", request->auth_user_request->username());
