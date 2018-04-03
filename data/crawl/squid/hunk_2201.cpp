         while (count > 0) {
             Token = (const char *) squid_kerb_proxy_auth(argv[1]);
             fprintf(stdout, "YR %s\n", Token ? Token : "NULL");
-            count--;
+            --count;
         }
         fprintf(stdout, "QQ\n");
     } else {
