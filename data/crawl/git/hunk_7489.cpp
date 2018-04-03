 
 	if (!strcmp("recursive", ep)) {
 		if (!value)
-			return error("%s: lacks value", var);
+			return config_error_nonbool(var);
 		fn->recursive = strdup(value);
 		return 0;
 	}