 	if (rc == LDAP_SUCCESS) {
 	    entry = ldap_first_entry(ld, res);
 	    if (entry) {
-                if (debug)
-                    printf("ldap dn: %s\n", ldap_get_dn(ld, entry));
-                if (edir_universal_passwd) {
-               
-                    /* allocate some memory for the universal password returned by NMAS */ 
-                    universal_password = malloc(universal_password_len);
-                    memset(universal_password, 0, universal_password_len);
-                    values = malloc(sizeof(char *));
-                    
-                    /* actually talk to NMAS to get a password */
-                    nmas_res = nmasldap_get_password(ld, ldap_get_dn(ld, entry), &universal_password_len, universal_password);
-                    if (nmas_res == NMAS_SUCCESS && universal_password) {
-                        if (debug)
-                          printf("NMAS returned value %s\n", universal_password);
-                        values[0] = universal_password;
-                    } else {
-                        if (debug)
-                          printf("Error reading Universal Password: %d = %s\n", nmas_res, ldap_err2string(nmas_res));
-                    }
-                } else {
-                    values = ldap_get_values(ld, entry, passattr);
-                }
+		if (debug)
+		    printf("ldap dn: %s\n", ldap_get_dn(ld, entry));
+		if (edir_universal_passwd) {
+
+		    /* allocate some memory for the universal password returned by NMAS */
+		    universal_password = malloc(universal_password_len);
+		    memset(universal_password, 0, universal_password_len);
+		    values = malloc(sizeof(char *));
+
+		    /* actually talk to NMAS to get a password */
+		    nmas_res = nmasldap_get_password(ld, ldap_get_dn(ld, entry), &universal_password_len, universal_password);
+		    if (nmas_res == NMAS_SUCCESS && universal_password) {
+			if (debug)
+			    printf("NMAS returned value %s\n", universal_password);
+			values[0] = universal_password;
+		    } else {
+			if (debug)
+			    printf("Error reading Universal Password: %d = %s\n", nmas_res, ldap_err2string(nmas_res));
+		    }
+		} else {
+		    values = ldap_get_values(ld, entry, passattr);
+		}
 	    } else {
 		ldap_msgfree(res);
 		return NULL;
 	    }
 	    if (!values) {
 		if (debug)
 		    printf("No attribute value found\n");
-                if (edir_universal_passwd)
-                   free(universal_password);
+		if (edir_universal_passwd)
+		    free(universal_password);
 		ldap_msgfree(res);
 		return NULL;
 	    }
