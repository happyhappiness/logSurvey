 			|| ((type_instance != NULL)
 				&& (strlen (type_instance) >= sizeof (vl.type_instance))))
 	{
-		print_to_socket (fh, "-1 Identifier too long.\n");
+		cmd_error (CMD_PARSE_ERROR, err, "Identifier too long.");
 		sfree (identifier_copy);
-		return (-1);
+		return (CMD_PARSE_ERROR);
 	}
 
 	sstrncpy (vl.host, hostname, sizeof (vl.host));
