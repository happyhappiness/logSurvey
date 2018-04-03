 	rfc1738_unescape(passwd);
 	pwd = getpwnam(user);
 	if (pwd == NULL) {
-	    printf(ERR);
+	    printf("ERR No such user\n");
 	} else {
 	    if (strcmp(pwd->pw_passwd, (char *) crypt(passwd, pwd->pw_passwd))) {
-		printf(ERR);
+		printf("ERR Wrong password\n");
 	    } else {
 		printf(OK);
 	    }
