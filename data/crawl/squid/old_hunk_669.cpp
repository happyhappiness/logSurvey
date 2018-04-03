            break;
        }

        option = strtok(NULL, ":,");
    }

    safe_free(tmp);
    }

#if SSL_OP_NO_SSLv2
    // compliance with RFC 6176: Prohibiting Secure Sockets Layer (SSL) Version 2.0
