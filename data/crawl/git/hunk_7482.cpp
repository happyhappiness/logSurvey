 	}
 
 	if (!value)
-		return error("%s: lacks value", var);
+		return config_error_nonbool(var);
 	drv->cmd = strdup(value);
 	return 0;
 }