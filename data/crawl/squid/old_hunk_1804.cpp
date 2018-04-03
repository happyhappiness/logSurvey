            return false;
        }
        close(sockfd);
        status = strtol(buffer+8,0,10);
        delete[] buffer;
    }

