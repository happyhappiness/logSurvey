 	    break;
 	case 'E':
 #if defined(NETSCAPE_SSL)
-		sslpath = value;
-		if (port == LDAP_PORT)
-		    port = LDAPS_PORT;
+	    sslpath = value;
+	    if (port == LDAP_PORT)
+		port = LDAPS_PORT;
 #else
-		fprintf(stderr, PROGRAM_NAME " ERROR: -E unsupported with this LDAP library\n");
-		exit(1);
+	    fprintf(stderr, PROGRAM_NAME " ERROR: -E unsupported with this LDAP library\n");
+	    exit(1);
 #endif
-		break;
+	    break;
 	case 'c':
-		connect_timeout = atoi(value);
-		break;
+	    connect_timeout = atoi(value);
+	    break;
 	case 't':
-		timelimit = atoi(value);
-		break;
+	    timelimit = atoi(value);
+	    break;
 	case 'a':
 	    if (strcmp(value, "never") == 0)
 		aliasderef = LDAP_DEREF_NEVER;
