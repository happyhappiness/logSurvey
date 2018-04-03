 	}
 	argv++;
 	argc--;
-	switch(option) {
+	switch (option) {
 	case 'b':
-		basedn = value;
-		break;
+	    basedn = value;
+	    break;
 	case 'f':
-		searchfilter = value;
-		break;
+	    searchfilter = value;
+	    break;
 	case 'u':
-		userattr = value;
-		break;
+	    userattr = value;
+	    break;
 	case 's':
-		if (strcmp(value, "base") == 0)
-		    searchscope = LDAP_SCOPE_BASE;
-		else if (strcmp(value, "one") == 0)
-		    searchscope = LDAP_SCOPE_ONELEVEL;
-		else if (strcmp(value, "sub") == 0)
-		    searchscope = LDAP_SCOPE_SUBTREE;
-		else {
-		    fprintf(stderr, "squid_ldap_auth: ERROR: Unknown search scope '%s'\n", value);
-		    exit(1);
-		}
-		break;
+	    if (strcmp(value, "base") == 0)
+		searchscope = LDAP_SCOPE_BASE;
+	    else if (strcmp(value, "one") == 0)
+		searchscope = LDAP_SCOPE_ONELEVEL;
+	    else if (strcmp(value, "sub") == 0)
+		searchscope = LDAP_SCOPE_SUBTREE;
+	    else {
+		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown search scope '%s'\n", value);
+		exit(1);
+	    }
+	    break;
 	case 'a':
-		if (strcmp(value, "never") == 0)
-		    aliasderef = LDAP_DEREF_NEVER;
-		else if (strcmp(value, "always") == 0)
-		    aliasderef = LDAP_DEREF_ALWAYS;
-		else if (strcmp(value, "search") == 0)
-		    aliasderef = LDAP_DEREF_SEARCHING;
-		else if (strcmp(value, "find") == 0)
-		    aliasderef = LDAP_DEREF_FINDING;
-		else {
-		    fprintf(stderr, "squid_ldap_auth: ERROR: Unknown alias dereference method '%s'\n", value);
-		    exit(1);
-		}
-		break;
+	    if (strcmp(value, "never") == 0)
+		aliasderef = LDAP_DEREF_NEVER;
+	    else if (strcmp(value, "always") == 0)
+		aliasderef = LDAP_DEREF_ALWAYS;
+	    else if (strcmp(value, "search") == 0)
+		aliasderef = LDAP_DEREF_SEARCHING;
+	    else if (strcmp(value, "find") == 0)
+		aliasderef = LDAP_DEREF_FINDING;
+	    else {
+		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown alias dereference method '%s'\n", value);
+		exit(1);
+	    }
+	    break;
 	case 'D':
-		binddn = value;
-		break;
+	    binddn = value;
+	    break;
 	case 'w':
-		bindpasswd = value;
-		break;
+	    bindpasswd = value;
+	    break;
 	case 'p':
-		persistent = !persistent;
-		break;
+	    persistent = !persistent;
+	    break;
 	case 'R':
-		noreferrals = !noreferrals;
-		break;
+	    noreferrals = !noreferrals;
+	    break;
 	default:
-		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown command line option '%c'\n", option);
-		exit(1);
+	    fprintf(stderr, "squid_ldap_auth: ERROR: Unknown command line option '%c'\n", option);
+	    exit(1);
 	}
     }
 
