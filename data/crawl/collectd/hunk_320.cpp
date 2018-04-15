 	}
 	else if (strcasecmp ("RandomTimeout", key) == 0)
         {
-		random_timeout = atoi (value);
-		if( random_timeout < 0 )
+		int tmp;
+
+		tmp = atoi (value);
+		if (tmp < 0)
+		{
+			fprintf (stderr, "rrdtool: `RandomTimeout' must "
+					"be greater than or equal to zero.\n");
+			ERROR ("rrdtool: `RandomTimeout' must "
+					"be greater then or equal to zero.");
+		}
+		else
 		{
-		fprintf (stderr, "rrdtool: `RandomTimeout' must "
-			 "be greater than or equal to zero.\n");
-		ERROR ("rrdtool: `RandomTimeout' must "
-		       "be greater then or equal to zero.\n");
+			random_timeout = tmp;
 		}
-		else if (random_timeout==0) {random_timeout=1;}
-		else {random_timeout_mod = random_timeout * 2;}
 	}
 	else
 	{