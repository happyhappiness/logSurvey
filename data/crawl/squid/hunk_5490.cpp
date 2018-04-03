 	    else if (strcmp(value, "find") == 0)
 		aliasderef = LDAP_DEREF_FINDING;
 	    else {
-		fprintf(stderr, "squid_ldap_match: ERROR: Unknown alias dereference method '%s'\n", value);
+		fprintf(stderr, PROGRAM_NAME " ERROR: Unknown alias dereference method '%s'\n", value);
 		exit(1);
 	    }
 	    break;
