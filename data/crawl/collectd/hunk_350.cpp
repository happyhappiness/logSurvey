 	return (status_code);
 } /* int do_check_con_sum */
 
-static int do_check_con_percentage (int values_num, double *values, char **values_names)
+static int do_check_con_percentage (size_t values_num,
+		double *values, char **values_names)
 {
-        int i;
+	int i;
+	double sum = 0.0;
 	double percentage;
 
-	if (values_num != 2)
-		return (RET_WARNING);
-	if (isnan (values[0]) || isnan (values[1]))
-		return (RET_WARNING);
-	if ((values[0] + values[1]) == 0)
-		return (RET_WARNING);
+	const char *status_str  = "UNKNOWN";
+	int         status_code = RET_UNKNOWN;
 
-        percentage = 100 * values[1] / ( values[0] + values[1] );
+	if ((values_num < 1) || (isnan (values[0])))
+	{
+		printf ("WARNING: The first value is not defined\n");
+		return (RET_WARNING);
+	}
 
-	printf ("%lf percentage |", percentage);
 	for (i = 0; i < values_num; i++)
-		printf (" %s=%lf;;;;", values_names[i], values[i]);
+		if (!isnan (values[i]))
+			sum += values[i];
+
+	if (sum == 0.0)
+	{
+		printf ("WARNING: Values sum up to zero\n");
+		return (RET_WARNING);
+	}
+
+	percentage = 100.0 * values[0] / sum;
 
 	if (match_range (&range_critical_g, percentage) != 0)
 	{
-		printf ("CRITICAL: percentage = %lf\n", percentage);
-		return (RET_CRITICAL);
+		status_str  = "CRITICAL";
+		status_code = RET_CRITICAL;
 	}
 	else if (match_range (&range_warning_g, percentage) != 0)
 	{
-		printf ("WARNING: percentage = %lf\n", percentage);
-		return (RET_WARNING);
-        }
+		status_str  = "WARNING";
+		status_code = RET_WARNING;
+	}
+	else
+	{
+		status_str  = "OKAY";
+		status_code = RET_OKAY;
+	}
 
-        printf ("OKAY: percentage = %lf\n", percentage);
-        return (RET_OKAY);
+	printf ("%s: %lf percent |", status_str, percentage);
+	for (i = 0; i < values_num; i++)
+		printf (" %s=%lf;;;;", values_names[i], values[i]);
+	return (status_code);
 } /* int do_check_con_percentage */
 
 static int do_check (void)
