            return false;
        }
        close(sockfd);
        int64_t s = strtol(buffer+8,0,10);
        if (s > 0 && s < 1000)
            status = s;
        else {
            // error while reading squid's answer
            fprintf( stderr, "invalid HTTP status in reply: %s\n", buffer+8);
        }
        delete[] buffer;
    }

