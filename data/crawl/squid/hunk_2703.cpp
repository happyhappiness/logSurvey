             buf.Printf("X-Client-IP: %s\r\n", client_addr.NtoA(ntoabuf,MAX_IPSTRLEN));
     }
 
-    if (TheConfig.send_client_username && request)
+    if (TheConfig.send_username && request)
         makeUsernameHeader(request, buf);
 
     // fprintf(stderr, "%s\n", buf.content());
