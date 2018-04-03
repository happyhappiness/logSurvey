             return false;
         }
 
-        int size = strlen(buffer);
-        if ( write( sockfd, buffer, size ) != size ) {
+        int content_size = strlen(buffer);
+        if ( write( sockfd, buffer, content_size ) != content_size ) {
             // error while talking to squid
             fprintf( stderr, "unable to talk to server: %s\n", strerror(errno) );
             close(sockfd);
