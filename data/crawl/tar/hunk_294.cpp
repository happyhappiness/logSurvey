 void
 argmatch_invalid (const char *context, const char *value, int problem)
 {
-  enum quoting_style saved_quoting_style;
-  char const *format;
-
-  /* Make sure to have a good quoting style to report errors.
-     literal is insane here. */
-  saved_quoting_style = get_quoting_style (NULL);
-  set_quoting_style (NULL, ARGMATCH_QUOTING_STYLE);
-
-  format = (problem == -1
-	    ? _("invalid argument `%s' for `%s'")
-	    : _("ambiguous argument `%s' for `%s'"));
-
-  error (0, 0, format, quotearg (value), context);
+  char const *format = (problem == -1
+			? _("invalid argument %s for %s")
+			: _("ambiguous argument %s for %s"));
 
-  set_quoting_style (NULL, saved_quoting_style);
+  error (0, 0, format, quotearg_n_style (0, ARGMATCH_QUOTING_STYLE, value),
+	 quote_n (1, context));
 }
 
 /* List the valid arguments for argmatch.
