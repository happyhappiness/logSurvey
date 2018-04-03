 static int
 decode_addr(const char *asc, struct in_addr *addr, struct in_addr *mask)
 {
-    u_num32 a = 0;
+    u_num32 a;
     int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
     struct hostent *hp = NULL;
 
     switch (sscanf(asc, "%d.%d.%d.%d", &a1, &a2, &a3, &a4)) {
     case 4:			/* a dotted quad */
-	if ((a = (u_num32) inet_addr(asc)) != inaddr_none ||
-	    !strcmp(asc, "255.255.255.255")) {
-	    addr->s_addr = a;
-	    /* inet_addr() outputs in network byte order */
+	if (!safe_inet_addr(asc, addr)) {
+	    debug(28, 0, "decode_addr: unsafe IP address: '%s'\n", asc);
+	    fatal("decode_addr: unsafe IP address");
 	}
 	break;
     case 1:			/* a significant bits value for a mask */
