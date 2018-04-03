 	fprintf(stderr, PROGRAM_NAME " ERROR, Failed to construct LDAP search filter. filter=\"%s\", user=\"%s\", group=\"%s\"\n", filter, member, group);
 	return 1;
     }
-
     if (debug)
 	fprintf(stderr, "group filter '%s', searchbase '%s'\n", filter, searchbase);
 
