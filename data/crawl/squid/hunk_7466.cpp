 	/* NOTREACHED */
     }
 
-    time_val = time(NULL);
-    time_string = ctime(&time_val);
+    time_string = ctime(&now);
 
     printf("<HTML><HEAD><TITLE>Cache Manager: %s:%s:%d</TITLE></HEAD>\n",
 	operation, hostname, portnum);
