 	rfc1738_unescape(user);
 	rfc1738_unescape(passwd);
 	if (!validUsername(user)) {
-	    printf("ERR\n");
+	    printf("ERR No such user\n");
 	    continue;
 	}
 	tryagain = (ld != NULL);
