 	}
 }
 
-int cf_callback_loadmodule (const char *shortvar, const char *var,
+/*
+ * `cf_callback_plugin_dispatch'
+ *   Send options within `plugin' sections to the plugin that requests it.
+ *
+ * <Plugin `current_module'>
+ *   `var' `value'
+ * </Plugin>
+ */
+int cf_callback_plugin_dispatch (const char *shortvar, const char *var,
 		const char *arguments, const char *value, lc_flags_t flags,
 		void *extra)
 {
 	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
 			shortvar, var, arguments, value);
 
-	if (nesting_depth == 0)
+	if ((nesting_depth == 0) || (current_module == NULL))
 	{
 		fprintf (stderr, ERR_NEEDS_SECTION, shortvar);
 		return (LC_CBRET_ERROR);
 	}
 
-	if (plugin_load (value))
-		syslog (LOG_ERR, "plugin_load (%s): failed to load plugin", shortvar);
+	/* Send the data to the plugin */
+	if (cf_dispatch (current_module, shortvar, value) < 0)
+		return (LC_CBRET_ERROR);
 
-	/* Return `okay' even if there was an error, because it's not a syntax
-	 * problem.. */
 	return (LC_CBRET_OKAY);
 }
 
