 		return (1);
 
 	return (0);
-} /* int parse_option */
+} /* int set_option */
+
+/*
+ * public API
+ */
 
-int handle_putval (FILE *fh, char *buffer)
+cmd_status_t cmd_parse_putval (char *buffer,
+		cmd_putval_t *ret_putval, cmd_error_handler_t *err)
 {
-	char *command;
 	char *identifier;
 	char *hostname;
 	char *plugin;
 	char *plugin_instance;
 	char *type;
 	char *type_instance;
 	int   status;
-	int   values_submitted;
 
 	char *identifier_copy;
 
 	const data_set_t *ds;
 	value_list_t vl = VALUE_LIST_INIT;
 	vl.values = NULL;
 
-	DEBUG ("utils_cmd_putval: handle_putval (fh = %p, buffer = %s);",
-			(void *) fh, buffer);
-
-	command = NULL;
-	status = parse_string (&buffer, &command);
-	if (status != 0)
-	{
-		print_to_socket (fh, "-1 Cannot parse command.\n");
-		return (-1);
-	}
-	assert (command != NULL);
-
-	if (strcasecmp ("PUTVAL", command) != 0)
-	{
-		print_to_socket (fh, "-1 Unexpected command: `%s'.\n", command);
-		return (-1);
-	}
-
 	identifier = NULL;
 	status = parse_string (&buffer, &identifier);
 	if (status != 0)
 	{
-		print_to_socket (fh, "-1 Cannot parse identifier.\n");
-		return (-1);
+		cmd_error (CMD_PARSE_ERROR, err, "Cannot parse identifier.");
+		return (CMD_PARSE_ERROR);
 	}
 	assert (identifier != NULL);
 
