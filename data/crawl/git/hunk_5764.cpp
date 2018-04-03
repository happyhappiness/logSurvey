 
 static int run_status(int code, const char *cmd_name)
 {
-	if (code < 0 && errno == ENOENT)
-		return error("execute of %s failed", cmd_name);
-	else if (code > 0)
+	if (code > 0)
 		error("%s exited with error code %d", cmd_name, code);
 	return code;
 }
