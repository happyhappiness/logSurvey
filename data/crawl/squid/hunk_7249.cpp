 {
     char *token;
     int i;
+    if (Config.Port.n_http == MAXHTTPPORTS) {
+	sprintf(fatal_str, "Limit of %d HTTP Ports exceeded, redefine MAXHTTPPORTS.\n",
+	    MAXHTTPPORTS);
+	fatal(fatal_str);
+    }
     GetInteger(i);
     if (i < 0)
 	i = 0;
-    Config.Port.http = (u_short) i;
+    Config.Port.http[Config.Port.n_http++] = (u_short) i;
 }
 
 static void
