        ska_base64_decode((char*)input_token.value, buf + 3, input_token.length);


        if ((input_token.length >= sizeof ntlmProtocol + 1) &&
                (!memcmp(input_token.value, ntlmProtocol, sizeof ntlmProtocol))) {
            if (debug)
