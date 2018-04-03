 	return (LC_CBRET_OKAY);
 }
 
-int cf_callback_section_mode (const char *shortvar, const char *var,
+/*
+ * `cf_callback_mode_loadmodule':
+ *   Load a plugin.
+ *
+ * <Mode xxx>
+ *   LoadPlugin `value'
+ * </Mode>
+ */
+int cf_callback_mode_loadmodule (const char *shortvar, const char *var,
 		const char *arguments, const char *value, lc_flags_t flags,
 		void *extra)
 {
 	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
 			shortvar, var, arguments, value);
 
-	if (flags == LC_FLAGS_SECTIONSTART)
+	if (nesting_depth == 0)
 	{
-		if (nesting_depth != 0)
-		{
-			fprintf (stderr, ERR_NOT_NESTED);
-			return (LC_CBRET_ERROR);
-		}
+		fprintf (stderr, ERR_NEEDS_SECTION, shortvar);
+		return (LC_CBRET_ERROR);
+	}
 
-		if (arguments == NULL)
-		{
-			fprintf (stderr, ERR_NEEDS_ARG, shortvar);
-			return (LC_CBRET_ERROR);
-		}
+	if (plugin_load (value))
+		syslog (LOG_ERR, "plugin_load (%s): failed to load plugin", value);
 
-		nesting_depth++;
+	/* Return `okay' even if there was an error, because it's not a syntax
+	 * problem.. */
+	return (LC_CBRET_OKAY);
+}
 
-		if (((operating_mode == MODE_CLIENT)
-					&& (strcasecmp (arguments, "Client") == 0))
-				|| ((operating_mode == MODE_SERVER)
-					&& (strcasecmp (arguments, "Server") == 0))
-				|| ((operating_mode == MODE_LOCAL)
-					&& (strcasecmp (arguments, "Local") == 0)))
-		{
-			return (LC_CBRET_OKAY);
-		}
-		else
-		{
-			return (LC_CBRET_IGNORESECTION);
-		}
-	}
-	else if (flags == LC_FLAGS_SECTIONEND)
-	{
-		nesting_depth--;
+/* XXX think about how to do the command line stuff */
+int cf_callback_mode_switch (const char *shortvar, const char *var,
+		const char *arguments, const char *value, lc_flags_t flags,
+		void *extra)
+{
+	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
+			shortvar, var, arguments, value);
 
-		return (LC_CBRET_OKAY);
-	}
+	if (strcasecmp (shortvar, "Client") == 0)
+		operating_mode = MODE_CLIENT;
+	else if (strcasecmp (shortvar, "Local") == 0)
+		operating_mode = MODE_LOCAL;
+	else if (strcasecmp (shortvar, "Server") == 0)
+		operating_mode = MODE_SERVER;
 	else
 	{
-		fprintf (stderr, ERR_SECTION_ONLY, shortvar);
+		fprintf (stderr, "cf_callback_mode_switch: Wrong mode!\n");
 		return (LC_CBRET_ERROR);
 	}
 
+	return (LC_CBRET_OKAY);
 }
 
-int cf_callback_section_module (const char *shortvar, const char *var,
+/*
+ * `cf_callback_plugin'
+ *   Start/end section `plugin'
+ *
+ * <Plugin `arguments'>
+ *   ...
+ * </Plugin>
+ */
+int cf_callback_plugin (const char *shortvar, const char *var,
 		const char *arguments, const char *value, lc_flags_t flags,
 		void *extra)
 {
