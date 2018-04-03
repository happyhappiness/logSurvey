 	return 0;
 }
 
+static int git_default_push_config(const char *var, const char *value)
+{
+	if (!strcmp(var, "push.default")) {
+		if (!value)
+			return config_error_nonbool(var);
+		else if (!strcmp(value, "nothing"))
+			push_default = PUSH_DEFAULT_NOTHING;
+		else if (!strcmp(value, "matching"))
+			push_default = PUSH_DEFAULT_MATCHING;
+		else if (!strcmp(value, "tracking"))
+			push_default = PUSH_DEFAULT_TRACKING;
+		else if (!strcmp(value, "current"))
+			push_default = PUSH_DEFAULT_CURRENT;
+		else {
+			error("Malformed value for %s: %s", var, value);
+			return error("Must be one of nothing, matching, "
+				     "tracking or current.");
+		}
+		return 0;
+	}
+
+	/* Add other config variables here and to Documentation/config.txt. */
+	return 0;
+}
+
 static int git_default_mailmap_config(const char *var, const char *value)
 {
 	if (!strcmp(var, "mailmap.file"))
