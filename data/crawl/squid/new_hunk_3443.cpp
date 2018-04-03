

        if (output_token.length) {
            spnegoToken = (const unsigned char*)output_token.value;
            spnegoTokenLength = output_token.length;
            token = (char*)xmalloc(ska_base64_encode_len(spnegoTokenLength));
            if (token == NULL) {
                if (debug)
