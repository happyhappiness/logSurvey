 		    exit(1);
 		}
 		break;
+	case 'D':
+		binddn = value;
+		break;
+	case 'w':
+		bindpasswd = value;
+		break;
+	case 'p':
+		persistent = !persistent;
+		break;
 	default:
 		fprintf(stderr, "squid_ldap_auth: ERROR: Unknown command line option '%c'\n", option);
 		exit(1);
 	}
     }
 	
     if (argc != 2) {
-	fprintf(stderr, "Usage: squid_ldap_auth [-b basedn] [-s searchscope] [-f searchfilter] ldap_server_name\n");
+	fprintf(stderr, "Usage: squid_ldap_auth [options] ldap_server_name\n\n");
+	fprintf(stderr, "\t-b basedn\t\tbase dn under which to search\n");
+	fprintf(stderr, "\t-f filter\t\tsearch filter to locate user DN\n");
+	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");
+	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
+	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
+	fprintf(stderr, "\t-p\t\t\tpersistent LDAP connection\n");
+	fprintf(stderr, "\n");
+	fprintf(stderr, "\tIf no search filter is specified, then the dn uid=user,basedn will\n\tbe used (same as specifying a search filter of 'uid=', but quicker\n\tas as there is no need to search for the user DN)\n\n");
+	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
 	exit(1);
     }
     ldapServer = (char *) argv[1];
 
     while (fgets(buf, 256, stdin) != NULL) {
-	/* You can put this ldap connect outside the loop, but i didn't want to 
-	 * have the connection open too much. If you have a site which will 
-	 * be doing >1 authentication per second, you should move this (and the 
-	 * below ldap_unbind()) outside the loop. 
-	 */
-	if ((ld = ldap_init(ldapServer, LDAP_PORT)) == NULL) {
-	    fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
-		ldapServer, LDAP_PORT);
-	    exit(1);
-	}
 	if ((p = strchr(buf, '\n')) != NULL)
 	    *p = '\0';		/* strip \n */
+	if ((p = strchr(buf, '\r')) != NULL)
+	    *p = '\0';		/* strip \r */
 
-	if ((user = strtok(buf, " ")) == NULL) {
+	user = buf;
+	if ((passwd = strrchr(buf, ' ')) == NULL) {
 	    printf("ERR\n");
 	    continue;
 	}
-	if ((passwd = strtok(NULL, "")) == NULL) {
-	    printf("ERR\n");
-	    continue;
+	*passwd++ = '\0';	/* Cut in username,password */
+	tryagain = 1;
+recover:
+	if (ld == NULL) {
+	    if ((ld = ldap_init(ldapServer, LDAP_PORT)) == NULL) {
+		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
+		    ldapServer, LDAP_PORT);
+		exit(1);
+	    }
 	}
-	if (checkLDAP(ld, user, passwd) != 0) {
+	rc = checkLDAP(ld, user, passwd);
+	if (rc != LDAP_SUCCESS) {
+	    if (tryagain && ld->ld_errno != LDAP_INVALID_CREDENTIALS) {
+		tryagain = 0;
+		ldap_unbind(ld);
+		ld = NULL;
+		goto recover;
+	    }
 	    printf("ERR\n");
-	    continue;
 	} else {
 	    printf("OK\n");
 	}
-	ldap_unbind(ld);
+	if (!persistent || (ld->ld_errno != LDAP_SUCCESS && ld->ld_errno != LDAP_INVALID_CREDENTIALS)) {
+	    ldap_unbind(ld);
+	    ld = NULL;
+	}
     }
+    if (ld)
+	ldap_unbind(ld);
     return 0;
 }
 
-int
+static int
 checkLDAP(LDAP * ld, char *userid, char *password)
 {
     char dn[256];
-    int result = 1;
 
+    if (!*password) {
+	/* LDAP can't bind with a blank password. Seen as "anonymous"
+	 * and always granted access
+	 */
+	return 1;
+    }
     if (searchfilter) {
 	char filter[256];
 	LDAPMessage *res = NULL;
 	LDAPMessage *entry;
 	char *searchattr[] = {NULL};
 	char *userdn;
 
+	if (binddn) {
+	    if (ldap_simple_bind_s(ld, binddn, bindpasswd) != LDAP_SUCCESS) {
+		fprintf(stderr, "squid_ldap_auth: WARNING, could not bind to binddn '%s'\n", binddn);
+		return 1;
+	    }
+	}
 	snprintf(filter, sizeof(filter), "%s%s", searchfilter, userid);
 	if (ldap_search_s(ld, basedn, searchscope, filter, searchattr, 1, &res) != LDAP_SUCCESS)
 	    return 1;
