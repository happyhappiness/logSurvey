      char *address;
      int code;
 {
-    int index;
-
     *tmp_error_buf = '\0';
     if (type < ERR_MIN || type > ERR_MAX)
-	fatal_dump("squid_error_url: type out of range.");
-    index = (int) (type - ERR_MIN);
+	fatal_dump("squid_error_request: type out of range.");
 
     sprintf(tmp_error_buf, "HTTP/1.0 %d Cache Detected Error\r\nContent-type: text/html\r\n\r\n", code);
     sprintf(tbuf, SQUID_REQUEST_ERROR_MSG,
