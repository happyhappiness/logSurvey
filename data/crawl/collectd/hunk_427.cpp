 		}
 		rrarows = tmp;
 	}
+	else if (strcasecmp ("RRATimespan", key) == 0)
+	{
+		char *saveptr = NULL;
+		char *dummy;
+		char *ptr;
+		int *tmp_alloc;
+
+		dummy = value;
+		while ((ptr = strtok_r (dummy, ", \t", &saveptr)) != NULL)
+		{
+			dummy = NULL;
+			
+			tmp_alloc = realloc (rra_timespans_custom,
+					sizeof (int) * (rra_timespans_custom_num + 1));
+			if (tmp_alloc == NULL)
+			{
+				fprintf (stderr, "rrdtool: realloc failed.\n");
+				return (1);
+			}
+			rra_timespans_custom = tmp_alloc;
+			rra_timespans_custom[rra_timespans_custom_num] = atoi (ptr);
+			if (rra_timespans_custom[rra_timespans_custom_num] != 0)
+				rra_timespans_custom_num++;
+		} /* while (strtok_r) */
+
+	}
 	else if (strcasecmp ("XFF", key) == 0)
 	{
 		double tmp = atof (value);