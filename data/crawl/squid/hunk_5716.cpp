 	    printf("ERR\n");
 	    continue;
 	}
-	res = get_nis_password(user, nispasswd, nisdomain, nismap);
+	nispasswd = get_nis_password(user, nisdomain, nismap);
 
-	if (res) {
+	if (!nispasswd) {
 	    /* User does not exist */
 	    printf("ERR\n");
-	} else if (strcmp(nispasswd, (char *) crypt(passwd, nispasswd))) {
-	    /* Password incorrect */
-	    printf("ERR\n");
-	} else {
+	} else if (strcmp(nispasswd, (char *) crypt(passwd, nispasswd)) == 0) {
 	    /* All ok !, thanks... */
 	    printf("OK\n");
+	} else {
+	    /* Password incorrect */
+	    printf("ERR\n");
 	}
     }
     exit(0);