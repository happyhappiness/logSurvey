 			num_okay++;
 	}
 
-	if ((num_critical != 0) || (values_num == 0))
+	printf ("%i critical, %i warning, %i okay",
+			num_critical, num_warning, num_okay);
+	if (values_num > 0)
 	{
-		printf ("CRITICAL: %i critical, %i warning, %i okay\n",
-				num_critical, num_warning, num_okay);
-		return (RET_CRITICAL);
+		printf (" |");
+		for (i = 0; i < values_num; i++)
+			printf (" %s=%lf;;;;", values_names[i], values[i]);
 	}
+	printf ("\n");
+
+	if ((num_critical != 0) || (values_num == 0))
+		return (RET_CRITICAL);
 	else if (num_warning != 0)
-	{
-		printf ("WARNING: %i warning, %i okay\n",
-				num_warning, num_okay);
 		return (RET_WARNING);
-	}
-	else
-	{
-		printf ("OKAY: %i okay\n", num_okay);
-		return (RET_OKAY);
-	}
 
-	return (RET_UNKNOWN);
+	return (RET_OKAY);
 } /* int do_check_con_none */
 
 int do_check_con_average (int values_num, double *values, char **values_names)
 {
 	int i;
 	double total;
 	int total_num;
+	double average;
 
 	total = 0.0;
 	total_num = 0;