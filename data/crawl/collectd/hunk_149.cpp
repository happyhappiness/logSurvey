 		sstrncpy (vl.type_instance, type_instance, sizeof (vl.type_instance));
 
 	ds = plugin_get_ds (type);
-	if (ds == NULL) {
-		print_to_socket (fh, "-1 Type `%s' isn't defined.\n", type);
+	if (ds == NULL)
+	{
+		cmd_error (CMD_PARSE_ERROR, err, "1 Type `%s' isn't defined.", type);
 		sfree (identifier_copy);
-		return (-1);
+		return (CMD_PARSE_ERROR);
 	}
 
 	/* Free identifier_copy */
