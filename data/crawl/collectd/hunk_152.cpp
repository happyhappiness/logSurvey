 		status = parse_string (&buffer, &string);
 		if (status != 0)
 		{
-			print_to_socket (fh, "-1 Misformatted value.\n");
-			sfree (vl.values);
-			return (-1);
+			cmd_error (CMD_PARSE_ERROR, err, "Misformatted value.");
+			cmd_destroy_putval (ret_putval);
+			return (CMD_PARSE_ERROR);
 		}
 		assert (string != NULL);
 
 		status = parse_values (string, &vl, ds);
 		if (status != 0)
 		{
-			print_to_socket (fh, "-1 Parsing the values string failed.\n");
-			sfree (vl.values);
-			return (-1);
+			cmd_error (CMD_PARSE_ERROR, err, "Parsing the values string failed.");
+			cmd_destroy_putval (ret_putval);
+			return (CMD_PARSE_ERROR);
 		}
 
-		plugin_dispatch_values (&vl);
-		values_submitted++;
+		tmp = (value_list_t *) realloc (ret_putval->vl,
+				(ret_putval->vl_num + 1) * sizeof(*ret_putval->vl));
+		if (tmp == NULL)
+		{
+			cmd_error (CMD_ERROR, err, "realloc failed.");
+			cmd_destroy_putval (ret_putval);
+			return (CMD_ERROR);
+		}
+
+		ret_putval->vl = tmp;
+		ret_putval->vl_num++;
+		memcpy (&ret_putval->vl[ret_putval->vl_num - 1], &vl, sizeof (vl));
 	} /* while (*buffer != 0) */
 	/* Done parsing the options. */
 
-	if (fh!=stdout)
-		print_to_socket (fh, "0 Success: %i %s been dispatched.\n",
-			values_submitted,
-			(values_submitted == 1) ? "value has" : "values have");
+	return (CMD_OK);
+} /* cmd_status_t cmd_parse_putval */
 
-	sfree (vl.values);
-	return (0);
-} /* int handle_putval */
+void cmd_destroy_putval (cmd_putval_t *putval)
+{
+	size_t i;
+
+	if (putval == NULL)
+		return;
+
+	sfree (putval->identifier);
+
+	for (i = 0; i < putval->vl_num; ++i)
+	{
+		sfree (putval->vl[i].values);
+		meta_data_destroy (putval->vl[i].meta);
+		putval->vl[i].meta = NULL;
+	}
+	sfree (putval->vl);
+	putval->vl = NULL;
+	putval->vl_num = 0;
+} /* void cmd_destroy_putval */
+
+cmd_status_t cmd_handle_putval (FILE *fh, char *buffer)
+{
+	cmd_error_handler_t err = { cmd_error_fh, fh };
+	cmd_t cmd;
+	size_t i;
+
+	int status;
+
+	DEBUG ("utils_cmd_putval: cmd_handle_putval (fh = %p, buffer = %s);",
+			(void *) fh, buffer);
+
+	if ((status = cmd_parse (buffer, &cmd, &err)) != CMD_OK)
+		return (status);
+	if (cmd.type != CMD_PUTVAL)
+	{
+		cmd_error (CMD_UNKNOWN_COMMAND, &err, "Unexpected command: `%s'.",
+				CMD_TO_STRING (cmd.type));
+		cmd_destroy (&cmd);
+		return (CMD_UNKNOWN_COMMAND);
+	}
+
+	for (i = 0; i < cmd.cmd.putval.vl_num; ++i)
+		plugin_dispatch_values (&cmd.cmd.putval.vl[i]);
+
+	if (fh != stdout)
+		cmd_error (CMD_OK, &err, "Success: %i %s been dispatched.",
+				(int)cmd.cmd.putval.vl_num,
+				(cmd.cmd.putval.vl_num == 1) ? "value has" : "values have");
+
+	cmd_destroy (&cmd);
+	return (CMD_OK);
+} /* int cmd_handle_putval */
 
-int create_putval (char *ret, size_t ret_len, /* {{{ */
+int cmd_create_putval (char *ret, size_t ret_len, /* {{{ */
 	const data_set_t *ds, const value_list_t *vl)
 {
 	char buffer_ident[6 * DATA_MAX_NAME_LEN];
