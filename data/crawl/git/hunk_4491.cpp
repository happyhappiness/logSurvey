 {
 	const char *c = color(WT_STATUS_HEADER, s);
 
-	status_printf_ln(s, c, "Unmerged paths:");
+	status_printf_ln(s, c, _("Unmerged paths:"));
 	if (!advice_status_hints)
 		return;
 	if (s->in_merge)
 		;
 	else if (!s->is_initial)
-		status_printf_ln(s, c, "  (use \"git reset %s <file>...\" to unstage)", s->reference);
+		status_printf_ln(s, c, _("  (use \"git reset %s <file>...\" to unstage)"), s->reference);
 	else
-		status_printf_ln(s, c, "  (use \"git rm --cached <file>...\" to unstage)");
-	status_printf_ln(s, c, "  (use \"git add/rm <file>...\" as appropriate to mark resolution)");
+		status_printf_ln(s, c, _("  (use \"git rm --cached <file>...\" to unstage)"));
+	status_printf_ln(s, c, _("  (use \"git add/rm <file>...\" as appropriate to mark resolution)"));
 	status_printf_ln(s, c, "");
 }
 
