            /* we're waiting for a response from the client. Pass it the blob */
            debugs(29, 9, "AuthNTLMConfig::fixHeader: Sending type:" << type << " header: 'NTLM " << ntlm_request->server_blob << "'");
            httpHeaderPutStrf(&rep->header, type, "NTLM %s", ntlm_request->server_blob);
            safe_free(ntlm_request->server_blob);
            break;

