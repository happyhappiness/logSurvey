         urldecode(passwd, ptr, MAXPASS);
 
         if (authenticate(sockfd, username, passwd))
-            printf("OK\n");
+            SEND_OK("");
         else
-            printf("ERR\n");
+            SEND_ERR("");
     }
     close(sockfd);
     exit(1);
