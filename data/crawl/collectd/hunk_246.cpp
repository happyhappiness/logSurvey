 		return (RET_UNKNOWN);
 	}
 
+	status = lcc_sort_identifiers (connection, ret_ident, ret_ident_num);
+	if (status != 0) {
+		printf ("UNKNOWN: %s\n", lcc_strerror (connection));
+		if (ret_ident != NULL)
+			free (ret_ident);
+		return (RET_UNKNOWN);
+	}
+
 	for (i = 0; i < ret_ident_num; ++i) {
 		char id[1024];
 
 		if ((hostname_g != NULL) && (strcasecmp (hostname_g, ret_ident[i].host)))
 			continue;
 
+		if ((hostname == NULL) || strcasecmp (hostname, ret_ident[i].host))
+		{
+			if (hostname != NULL)
+				free (hostname);
+			hostname = strdup (ret_ident[i].host);
+			printf ("Host: %s\n", hostname);
+		}
+
+		/* empty hostname; not to be printed again */
+		ret_ident[i].host[0] = '\0';
+
 		status = lcc_identifier_to_string (connection,
 				id, sizeof (id), ret_ident + i);
 		if (status != 0) {
