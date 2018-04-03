                 snprintf(buf, BUFSIZ, "Authorization: Negotiate %s\r\n", GSSAPI_token(host));
                 strcat(msg, buf);
             } else
-                fprintf(stderr, "ERROR: server host missing\n");
+                std::cerr << "ERROR: server host missing" << std::endl;
         }
         if (proxy_neg) {
             if (hostname) {
                 snprintf(buf, BUFSIZ, "Proxy-Authorization: Negotiate %s\r\n", GSSAPI_token(hostname));
                 strcat(msg, buf);
             } else
-                fprintf(stderr, "ERROR: proxy server host missing\n");
+                std::cerr << "ERROR: proxy server host missing" << std::endl;
         }
 #endif
 
