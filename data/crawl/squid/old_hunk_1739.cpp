        }

        /* Send the HTTP request */
        bytesWritten = mywrite(conn, msg, strlen(msg));

        if (bytesWritten < 0) {
