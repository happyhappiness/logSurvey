   SSL_connect (*con);  
   if ((*con)->state != SSL_ST_OK)
     return 1;
+  /*while((SSLerror=ERR_get_error())!=0)
+    printf("%s\n", ERR_error_string(SSLerror,NULL));*/
+
   return 0;
 }
 
