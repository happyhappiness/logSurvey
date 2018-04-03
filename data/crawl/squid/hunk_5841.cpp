 	}
 	ldap_unbind(ld);
     }
+    return 0;
 }
 
-
-
 int
 checkLDAP(LDAP * ld, char *userid, char *password)
 {
-    char str[256];
+    char dn[256];
+    int result = 1;
 
-    /*sprintf(str,"uid=[%s][%s], %s",userid, password, SEARCHBASE); */
-    sprintf(str, "uid=%s, %s", userid, SEARCHBASE);
+    if (searchfilter) {
+	char filter[256];
+	LDAPMessage *res = NULL;
+	LDAPMessage *entry;
+	char *searchattr[] = {NULL};
+	char *userdn;
 
-    if (ldap_simple_bind_s(ld, str, password) != LDAP_SUCCESS) {
-	/*fprintf(stderr, "\nUnable to bind\n"); */
-	return 33;
+	snprintf(filter, sizeof(filter), "%s%s", searchfilter, userid);
+	if (ldap_search_s(ld, basedn, searchscope, filter, searchattr, 1, &res) != LDAP_SUCCESS)
+	    return 1;
+	entry = ldap_first_entry(ld, res);
+	if (!entry) {
+	    ldap_msgfree(res);
+	    return 1;
+	}
+	userdn = ldap_get_dn(ld, entry);
+	if (!userdn) {
+	    ldap_msgfree(res);
+	    return 1;
+	}
+	snprintf(dn, sizeof(dn), "%s", userdn);
+	free(userdn);
+	ldap_msgfree(res);
+    } else {
+	snprintf(dn, sizeof(dn), "uid=%s, %s", userid, basedn);
     }
-    return 0;
+
+    if (ldap_simple_bind_s(ld, dn, password) == LDAP_SUCCESS)
+	result = 0;
+
+    return result;
 }