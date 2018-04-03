 	value_list_t vl = VALUE_LIST_INIT;
 	size_t i;
 
+	if ((ret_putval == NULL) || (opts == NULL))
+	{
+		errno = EINVAL;
+		cmd_error (CMD_ERROR, err, "Invalid arguments to cmd_parse_putval.");
+		return (CMD_ERROR);
+	}
+
 	if (argc < 2)
 	{
 		cmd_error (CMD_PARSE_ERROR, err,
