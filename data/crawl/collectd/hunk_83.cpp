 		return (CMD_PARSE_ERROR);
 	}
 
-	/* Free identifier_copy */
 	hostname = NULL;
 	plugin = NULL; plugin_instance = NULL;
 	type = NULL;   type_instance = NULL;
-	sfree (identifier_copy);
 
 	vl.values_len = ds->ds_num;
 	vl.values = malloc (vl.values_len * sizeof (*vl.values));
 	if (vl.values == NULL)
 	{
 		cmd_error (CMD_ERROR, err, "malloc failed.");
+		sfree (identifier_copy);
 		return (CMD_ERROR);
 	}
 
-	ret_putval->identifier = strdup (identifier);
+	ret_putval->identifier = identifier_copy;
 	if (ret_putval->identifier == NULL)
 	{
 		cmd_error (CMD_ERROR, err, "malloc failed.");
 		cmd_destroy_putval (ret_putval);
 		return (CMD_ERROR);
 	}
 
-	/* All the remaining fields are part of the optionlist. */
-	while (*buffer != 0)
+	/* All the remaining fields are part of the option list. */
+	for (i = 1; i < argc; ++i)
 	{
 		value_list_t *tmp;
 
-		char *string = NULL;
-		char *value  = NULL;
+		char *key   = NULL;
+		char *value = NULL;
 
-		status = parse_option (&buffer, &string, &value);
-		if (status < 0)
+		status = cmd_parse_option (argv[i], &key, &value, err);
+		if (status == CMD_OK)
 		{
-			/* parse_option failed, buffer has been modified.
-			 * => we need to abort */
-			cmd_error (CMD_PARSE_ERROR, err, "Misformatted option.");
-			cmd_destroy_putval (ret_putval);
-			return (CMD_PARSE_ERROR);
-		}
-		else if (status == 0)
-		{
-			assert (string != NULL);
+			assert (key != NULL);
 			assert (value != NULL);
-			set_option (&vl, string, value);
+			set_option (&vl, key, value);
 			continue;
 		}
-		/* else: parse_option but buffer has not been modified. This is
-		 * the default if no `=' is found.. */
-
-		status = parse_string (&buffer, &string);
-		if (status != 0)
+		else if (status != CMD_NO_OPTION)
 		{
-			cmd_error (CMD_PARSE_ERROR, err, "Misformatted value.");
+			/* parse_option failed, buffer has been modified.
+			 * => we need to abort */
 			cmd_destroy_putval (ret_putval);
-			return (CMD_PARSE_ERROR);
+			return (status);
 		}
-		assert (string != NULL);
+		/* else: cmd_parse_option did not find an option; treat this as a
+		 * value list. */
 
-		status = parse_values (string, &vl, ds);
+		status = parse_values (argv[i], &vl, ds);
 		if (status != 0)
 		{
 			cmd_error (CMD_PARSE_ERROR, err, "Parsing the values string failed.");
