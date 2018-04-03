 	}
 	entry = ldap_first_entry(search_ld, res);
 	if (!entry) {
+	    if (debug)
+		fprintf(stderr, "Ldap search returned nothing\n");
 	    ret = 1;
 	    goto search_done;
 	}
