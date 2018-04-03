 		    exit(1);
 		}
 		break;
+	case 'a':
+		if (strcmp(value, "never") == 0)
+		    aliasderef = LDAP_DEREF_NEVER;
+		else if (strcmp(value, "always") == 0)
+		    aliasderef = LDAP_DEREF_ALWAYS;
+		else if (strcmp(value, "search") == 0)
+		    aliasderef = LDAP_DEREF_SEARCHING;
+		else if (strcmp(value, "find") == 0)
+		    aliasderef = LDAP_DEREF_FINDING;
+		else {
+		    fprintf(stderr, "squid_ldap_auth: ERROR: Unknown alias dereference method '%s'\n", value);
+		    exit(1);
+		}
+		break;
 	case 'D':
 		binddn = value;
 		break;
