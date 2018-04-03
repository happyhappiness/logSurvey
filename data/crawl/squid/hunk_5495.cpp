 }
 
 static int
-searchLDAP(LDAP * ld, char *group, char *member, char *grouprdn)
+ldap_escape_value(char *filter, int size, const char *src)
+{
+    int n = 0;
+    while (size > 0 && *src) {
+	switch(*src) {
+	case '*':
+	case '(':
+	case ')':
+	case '\\':
+	    n += 3;
+	    size -= 3;
+	    if (size > 0) {
+		*filter++ = '\\';
+		snprintf(filter, 3, "%02x", (int)*src++);
+		filter+=2;
+	    }
+	    break;
+	default:
+	    *filter++ = *src++;
+	    n++;
+	    size--;
+	}
+    }
+    return n;
+}
+
+static int
+build_filter(char *filter, int size, const char *template, const char *user, const char *group)
+{
+    int n;
+    while(*template && size > 0) {
+	switch(*template) {
+	case '%':
+	    template++;
+	    switch (*template) {
+	    case 'u':
+	    case 'v':
+		template++;
+		n = ldap_escape_value(filter, size, user);
+		size -= n;
+		filter += n;
+		break;
+	    case 'g':
+	    case 'a':
+		template++;
+		n = ldap_escape_value(filter, size, group);
+		size -= n;
+		filter += n;
+		break;
+	    default:
+		fprintf(stderr, "ERROR: Unknown filter template string %%%c\n", *template);
+		return 1;
+		break;
+	    }
+	    break;
+	case '\\':
+	    template++;
+	    if (*template) {
+		*filter++ = *template++;
+		size--;
+	    }
+	    break;
+	default:
+	    *filter++ = *template++;
+	    size--;
+	    break;
+	}
+    }
+    if (size <= 0) {
+	fprintf(stderr, "ERROR: Filter too large\n");
+	return 1;
+    }
+    *filter = '\0';
+    return 0;
+}
+
+static int
+searchLDAPGroup(LDAP * ld, char *group, char *member, char *extension_dn)
 {
     char filter[256];
     static char searchbase[256];
     LDAPMessage *res = NULL;
     LDAPMessage *entry;
+    int rc;
 
-    if (grouprdn)
-	snprintf(searchbase, sizeof(searchbase), "%s,%s", grouprdn, basedn);
+    if (extension_dn && *extension_dn)
+	snprintf(searchbase, sizeof(searchbase), "%s,%s", extension_dn, basedn);
     else
 	snprintf(searchbase, sizeof(searchbase), "%s", basedn);
 
-    ldap_build_filter(filter, sizeof(filter), searchfilter, NULL, NULL, group, member, NULL);
-    if (debug)
-	printf("filter %s\n", filter);
+    if (build_filter(filter, sizeof(filter), searchfilter, member, group) != 0) {
+	fprintf(stderr, PROGRAM_NAME " ERROR, Failed to construct LDAP search filter. filter=\"%s\", user=\"%s\", group=\"%s\"\n", filter, member, group);
+	return 1;
+    }
 
+    if (debug)
+	fprintf(stderr, "filter %s\n", filter);
 
-    if (ldap_search_s(ld, searchbase, searchscope, filter, NULL, 1, &res) != LDAP_SUCCESS) {
-	int rc = ldap_result2error(ld, res, 0);
+    rc = ldap_search_s(ld, searchbase, searchscope, filter, NULL, 1, &res);
+    if (rc != LDAP_SUCCESS) {
 	if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
 	    /* Everything is fine. This is expected when referrals
 	     * are disabled.
 	     */
 	} else {
-	    fprintf(stderr, "squid_ldap_match: WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
+	    fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
+	    ldap_msgfree(res);
+	    return 1;
 	}
-	ldap_msgfree(res);
-	return 1;
     }
     entry = ldap_first_entry(ld, res);
     if (!entry) {
