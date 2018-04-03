 			&type, &type_instance);
 	if (status != 0)
 	{
-		DEBUG ("handle_putval: Cannot parse identifier `%s'.",
+		DEBUG ("cmd_handle_putval: Cannot parse identifier `%s'.",
 				identifier);
-		print_to_socket (fh, "-1 Cannot parse identifier `%s'.\n",
+		cmd_error (CMD_PARSE_ERROR, err, "Cannot parse identifier `%s'.",
 				identifier);
 		sfree (identifier_copy);
-		return (-1);
+		return (CMD_PARSE_ERROR);
 	}
 
 	if ((strlen (hostname) >= sizeof (vl.host))
