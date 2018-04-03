 					 const char *how)
 {
 	const char *c = color(WT_STATUS_HEADER, s);
-	status_printf_ln(s, c, "%s files:", what);
+	status_printf_ln(s, c, _("%s files:"), what);
 	if (!advice_status_hints)
 		return;
-	status_printf_ln(s, c, "  (use \"git %s <file>...\" to include in what will be committed)", how);
+	status_printf_ln(s, c, _("  (use \"git %s <file>...\" to include in what will be committed)"), how);
 	status_printf_ln(s, c, "");
 }
 
