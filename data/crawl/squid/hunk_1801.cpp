             return false;
         }
         memset( buffer+8, 0, 4 );
-        if ( read( sockfd, buffer, bufsize ) < 1 ) {
+        int readLen = read(sockfd, buffer, bufsize);
+        if (readLen < 1) {
             // error while reading squid's answer
             fprintf( stderr, "unable to read answer: %s\n", strerror(errno) );
             close(sockfd);
             delete[] buffer;
             return false;
         }
+        buffer[bufsize-1] = '\0';
         close(sockfd);
         int64_t s = strtol(buffer+8,0,10);
         if (s > 0 && s < 1000)
