 
 	if (!strcmp("name", ep)) {
 		if (!value)
-			return error("%s: lacks value", var);
+			return config_error_nonbool(var);
 		fn->description = strdup(value);
 		return 0;
 	}
 
 	if (!strcmp("driver", ep)) {
 		if (!value)
-			return error("%s: lacks value", var);
+			return config_error_nonbool(var);
 		/*
 		 * merge.<name>.driver specifies the command line:
 		 *
