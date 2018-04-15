 		}
 		xff = tmp;
 	}
+	else if (strcasecmp ("WritesPerSecond", key) == 0)
+	{
+		double wps = atof (value);
+
+		if (wps < 0.0)
+		{
+			fprintf (stderr, "rrdtool: `WritesPerSecond' must be "
+					"greater than or equal to zero.");
+			return (1);
+		}
+		else if (wps == 0.0)
+		{
+			write_rate = 0.0;
+		}
+		else
+		{
+			write_rate = 1.0 / wps;
+		}
+	}
 	else
 	{
 		return (-1);