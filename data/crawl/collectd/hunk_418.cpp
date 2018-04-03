 
 	if (match_range (&range_critical_g, total) != 0)
 	{
-		printf ("CRITICAL: Sum = %lf\n", total);
-		return (RET_CRITICAL);
+		status_str = "CRITICAL";
+		status_code = RET_CRITICAL;
 	}
 	else if (match_range (&range_warning_g, total) != 0)
 	{
-		printf ("WARNING: Sum = %lf\n", total);
-		return (RET_WARNING);
+		status_str = "WARNING";
+		status_code = RET_WARNING;
 	}
 	else
 	{
-		printf ("OKAY: Sum = %lf\n", total);
-		return (RET_OKAY);
+		status_str = "OKAY";
+		status_code = RET_OKAY;
 	}
 
-	return (RET_UNKNOWN);
+	printf ("%s: %g sum |", status_str, total);
+	for (i = 0; i < values_num; i++)
+		printf (" %s=%g;;;;", values_names[i], values[i]);
+	printf ("\n");
+
+	return (status_code);
 } /* int do_check_con_sum */
 
-int do_check (void)
+static int do_check (void)
 {
-	double  *values;
+	lcc_connection_t *connection;
+	gauge_t *values;
 	char   **values_names;
-	int      values_num;
+	size_t   values_num;
+	char address[1024];
+	char ident_str[1024];
+	lcc_identifier_t ident;
+	size_t i;
+	int status;
 
-	if (get_values (&values_num, &values, &values_names) != 0)
+	snprintf (address, sizeof (address), "unix:%s", socket_file_g);
+	address[sizeof (address) - 1] = 0;
+
+	snprintf (ident_str, sizeof (ident_str), "%s/%s",
+			hostname_g, value_string_g);
+	ident_str[sizeof (ident_str) - 1] = 0;
+
+	connection = NULL;
+	status = lcc_connect (address, &connection);
+	if (status != 0)
+	{
+		printf ("ERROR: Connecting to daemon at %s failed.\n",
+				socket_file_g);
+		return (RET_CRITICAL);
+	}
+
+	memset (&ident, 0, sizeof (ident));
+	status = lcc_string_to_identifier (connection, &ident, ident_str);
+	if (status != 0)
 	{
-		fputs ("ERROR: Cannot get values from daemon\n", stdout);
+		printf ("ERROR: Creating an identifier failed: %s.\n",
+				lcc_strerror (connection));
+		LCC_DESTROY (connection);
 		return (RET_CRITICAL);
 	}
 
+	status = lcc_getval (connection, &ident,
+			&values_num, &values, &values_names);
+	if (status != 0)
+	{
+		printf ("ERROR: Retrieving values from the daemon failed: %s.\n",
+				lcc_strerror (connection));
+		LCC_DESTROY (connection);
+		return (RET_CRITICAL);
+	}
+
+	LCC_DESTROY (connection);
+
+	status = RET_UNKNOWN;
 	if (consolitation_g == CON_NONE)
-		return (do_check_con_none (values_num, values, values_names));
+		status =  do_check_con_none (values_num, values, values_names);
 	else if (consolitation_g == CON_AVERAGE)
-		return (do_check_con_average (values_num, values, values_names));
+		status =  do_check_con_average (values_num, values, values_names);
 	else if (consolitation_g == CON_SUM)
-		return (do_check_con_sum (values_num, values, values_names));
+		status = do_check_con_sum (values_num, values, values_names);
 
 	free (values);
-	free (values_names); /* FIXME? */
+	if (values_names != NULL)
+		for (i = 0; i < values_num; i++)
+			free (values_names[i]);
+	free (values_names);
 
-	return (RET_UNKNOWN);
-}
+	return (status);
+} /* int do_check */
 
 int main (int argc, char **argv)
 {