            snprintf(buf, BUFSIZ, "Authorization: Basic %s\r\n", base64_encode(buf));
            strcat(msg, buf);
        }

        /* HTTP/1.0 may need keep-alive explicitly */
        if (strcmp(version, "1.0") == 0 && keep_alive)
