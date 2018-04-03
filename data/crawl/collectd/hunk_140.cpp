 
 	const data_set_t *ds;
 	value_list_t vl = VALUE_LIST_INIT;
-	vl.values = NULL;
+	size_t i;
 
-	identifier = NULL;
-	status = parse_string (&buffer, &identifier);
-	if (status != 0)
+	if (argc < 2)
 	{
-		cmd_error (CMD_PARSE_ERROR, err, "Cannot parse identifier.");
+		cmd_error (CMD_PARSE_ERROR, err,
+				"Missing identifier and/or value-list.");
 		return (CMD_PARSE_ERROR);
 	}
-	assert (identifier != NULL);
 
-	/* parse_identifier() modifies its first argument,
-	 * returning pointers into it */
+	identifier = argv[0];
+
+	/* parse_identifier() modifies its first argument, returning pointers into
+	 * it; retain the old value for later. */
 	identifier_copy = sstrdup (identifier);
 
-	status = parse_identifier (identifier_copy, &hostname,
+	status = parse_identifier (identifier, &hostname,
 			&plugin, &plugin_instance,
 			&type, &type_instance);
 	if (status != 0)
 	{
 		DEBUG ("cmd_handle_putval: Cannot parse identifier `%s'.",
-				identifier);
+				identifier_copy);
 		cmd_error (CMD_PARSE_ERROR, err, "Cannot parse identifier `%s'.",
-				identifier);
+				identifier_copy);
 		sfree (identifier_copy);
 		return (CMD_PARSE_ERROR);
 	}
