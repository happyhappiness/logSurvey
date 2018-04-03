            }
            exit(1);
        }

        /* Send the HTTP request */
        bytesWritten = mywrite(conn, msg, strlen(msg));