 {
 	if (!value)
 		return config_error_nonbool(var);
-	if (!strcmp(value, "never") || !strcmp(value, "false")) {
-		*expire = 0;
-		return 0;
-	}
-	*expire = approxidate(value);
+	if (parse_expiry_date(value, expire))
+		return error(_("%s' for '%s' is not a valid timestamp"),
+			     value, var);
 	return 0;
 }
 
