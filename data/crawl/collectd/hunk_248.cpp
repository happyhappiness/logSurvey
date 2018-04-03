 	exit (1);
 } /* void usage */
 
+static int do_listval (lcc_connection_t *connection)
+{
+	lcc_identifier_t *ret_ident = NULL;
+	size_t ret_ident_num = 0;
+
+	int status;
+	size_t i;
+
+	status = lcc_listval (connection, &ret_ident, &ret_ident_num);
+	if (status != 0) {
+		printf ("UNKNOWN: %s\n", lcc_strerror (connection));
+		if (ret_ident != NULL)
+			free (ret_ident);
+		return (RET_UNKNOWN);
+	}
+
+	for (i = 0; i < ret_ident_num; ++i) {
+		char id[1024];
+
+		status = lcc_identifier_to_string (connection,
+				id, sizeof (id), ret_ident + i);
+		if (status != 0) {
+			printf ("ERROR: listval: Failed to convert returned "
+					"identifier to a string: %s\n",
+					lcc_strerror (connection));
+			continue;
+		}
+
+		printf ("%s\n", id);
+	}
+
+	if (ret_ident != NULL)
+		free (ret_ident);
+	return (RET_OKAY);
+} /* int do_listval */
+
 static int do_check_con_none (size_t values_num,
 		double *values, char **values_names)
 {
