            fprintf(stdout, "BH Invalid negotiate request\n");
            continue;
        }
        length = base64_decode_len(buf+3);
        if (debug)
            fprintf(stderr, "%s| %s: Decode '%s' (decoded length: %d).\n",
                    LogTime(), PROGRAM, buf + 3, (int) length);

        if ((token = (char *)xmalloc(length)) == NULL) {
            fprintf(stderr, "%s| %s: Error allocating memory for token\n", LogTime(), PROGRAM);
            return 1;
        }

        length = base64_decode(token, length, buf+3);

        if ((static_cast<size_t>(length) >= sizeof(ntlmProtocol) + 1) &&
                (!memcmp(token, ntlmProtocol, sizeof ntlmProtocol))) {
