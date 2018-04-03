 		parse_date(*argv, &result);
 		if (sscanf(result.buf, "%lu %d", &t, &tz) == 2)
 			printf("%s -> %s\n",
-			       *argv, show_date(t, tz, DATE_ISO8601));
+			       *argv, show_date(t, tz, DATE_MODE(ISO8601)));
 		else
 			printf("%s -> bad\n", *argv);
 	}
