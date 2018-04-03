 	    for (k = 0; k < ipcount; k++) {
 		if ((token = strtok(NULL, w_space)) == NULL)
 		    fatal_dump("Invalid IP address");
-		i.addrs.in_addrs[k].s_addr = inet_addr(token);
+		if (!safe_inet_addr(token, &i.addrs.in_addrs[k]))
+		    fatal_dump("Invalid IP address");
 	    }
 	} else if (!strcmp(token, "$aliascount")) {
 	    if ((token = strtok(NULL, w_space)) == NULL)
