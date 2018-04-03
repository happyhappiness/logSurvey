 		else if (!strcmp(value, "always"))
 			autorebase = AUTOREBASE_ALWAYS;
 		else
-			return error("Malformed value for %s", var);
+			return error("malformed value for %s", var);
 		return 0;
 	}
 
