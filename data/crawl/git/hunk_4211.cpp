 	} else if (!strcmp(name, TRANS_OPT_DEPTH)) {
 		if (!value)
 			opts->depth = 0;
-		else
-			opts->depth = atoi(value);
+		else {
+			char *end;
+			opts->depth = strtol(value, &end, 0);
+			if (*end)
+				die("transport: invalid depth option '%s'", value);
+		}
 		return 0;
 	}
 	return 1;