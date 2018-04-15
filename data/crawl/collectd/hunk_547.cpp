 	return (NULL);
 }
 
-/* 
- * Functions for the actual parsing
+/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
+ * Functions for the actual parsing                                    *
+ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
+
+/*
+ * `cf_callback_mode'
+ *   Start/end the `mode' section
+ *
+ * <Mode `arguments'>
+ *   ...
+ * </Mode>
  */
-int cf_callback_dispatch (const char *shortvar, const char *var,
+int cf_callback_mode (const char *shortvar, const char *var,
 		const char *arguments, const char *value, lc_flags_t flags,
 		void *extra)
 {
 	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
 			shortvar, var, arguments, value);
 
-	if ((nesting_depth == 0) || (current_module == NULL))
+	if (flags == LC_FLAGS_SECTIONSTART)
 	{
-		fprintf (stderr, ERR_NEEDS_SECTION, shortvar);
-		return (LC_CBRET_ERROR);
+		if (nesting_depth != 0)
+		{
+			fprintf (stderr, ERR_NOT_NESTED);
+			return (LC_CBRET_ERROR);
+		}
+
+		if (arguments == NULL)
+		{
+			fprintf (stderr, ERR_NEEDS_ARG, shortvar);
+			return (LC_CBRET_ERROR);
+		}
+
+		nesting_depth++;
+
+		if (((operating_mode == MODE_CLIENT)
+					&& (strcasecmp (arguments, "Client") == 0))
+				|| ((operating_mode == MODE_SERVER)
+					&& (strcasecmp (arguments, "Server") == 0))
+				|| ((operating_mode == MODE_LOCAL)
+					&& (strcasecmp (arguments, "Local") == 0)))
+		{
+			return (LC_CBRET_OKAY);
+		}
+		else
+		{
+			return (LC_CBRET_IGNORESECTION);
+		}
 	}
+	else if (flags == LC_FLAGS_SECTIONEND)
+	{
+		nesting_depth--;
 
-	/* Send the data to the plugin */
-	if (cf_dispatch (current_module, shortvar, value) < 0)
+		return (LC_CBRET_OKAY);
+	}
+	else
+	{
+		fprintf (stderr, ERR_SECTION_ONLY, shortvar);
 		return (LC_CBRET_ERROR);
+	}
+
+}
+
+/*
+ * `cf_callback_mode_plugindir'
+ *   Change the plugin directory
+ *
+ * <Mode xxx>
+ *   PluginDir `value'
+ * </Mode>
+ */
+int cf_callback_mode_plugindir (const char *shortvar, const char *var,
+		const char *arguments, const char *value, lc_flags_t flags,
+		void *extra)
+{
+	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
+			shortvar, var, arguments, value);
+
+	plugin_set_dir (value);
 
 	return (LC_CBRET_OKAY);
 }
 
-int cf_callback_options_mode (const char *shortvar, const char *var,
+int cf_callback_mode_option (const char *shortvar, const char *var,
 		const char *arguments, const char *value, lc_flags_t flags,
 		void *extra)
 {
 	cf_mode_item_t *item;
 
+	DBG ("shortvar = %s, var = %s, arguments = %s, value = %s, ...",
+			shortvar, var, arguments, value);
+
 	if (extra == NULL)
 	{
 		fprintf (stderr, "No extra..?\n");
