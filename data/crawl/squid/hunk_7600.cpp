 	    ipcount = atoi(token);
 	    for (k = 0; k < ipcount; k++) {
 		if ((token = strtok(NULL, w_space)) == NULL)
-		    fatal_dump("Invalid IP address");
+		    fatal_dump("Invalid FQDN address");
 	    }
 	} else if (!strcmp(token, "$aliascount")) {
 	    if ((token = strtok(NULL, w_space)) == NULL)
