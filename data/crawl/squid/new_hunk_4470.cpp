            /* we're waiting for a response from the client. Pass it the blob */
            debugs(29, 9, "AuthNegotiateConfig::fixHeader: Sending type:" << type << " header: 'Negotiate " << negotiate_request->server_blob << "'");
            httpHeaderPutStrf(&rep->header, type, "Negotiate %s", negotiate_request->server_blob);
            safe_free(negotiate_request->server_blob);
            break;

