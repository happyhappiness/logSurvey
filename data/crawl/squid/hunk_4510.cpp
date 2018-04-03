 		printf("password: %s\n", password);
 	    if (password)
 		password = strdup(password);
-            if (edir_universal_passwd) {
-                free(values);
-                free(universal_password);
-            } else {
-	    ldap_value_free(values);
-            }
+	    if (edir_universal_passwd) {
+		free(values);
+		free(universal_password);
+	    } else {
+		ldap_value_free(values);
+	    }
 	    ldap_msgfree(res);
 	    return password;
 	} else {
