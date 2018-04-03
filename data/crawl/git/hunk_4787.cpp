 {
 	const char *c = color(WT_STATUS_HEADER, s);
 
-	color_fprintf_ln(s->fp, c, "# Unmerged paths:");
+	status_printf_ln(s, c, "Unmerged paths:");
 	if (!advice_status_hints)
 		return;
 	if (s->in_merge)
 		;
 	else if (!s->is_initial)
-		color_fprintf_ln(s->fp, c, "#   (use \"git reset %s <file>...\" to unstage)", s->reference);
+		status_printf_ln(s, c, "  (use \"git reset %s <file>...\" to unstage)", s->reference);
 	else
-		color_fprintf_ln(s->fp, c, "#   (use \"git rm --cached <file>...\" to unstage)");
-	color_fprintf_ln(s->fp, c, "#   (use \"git add/rm <file>...\" as appropriate to mark resolution)");
-	color_fprintf_ln(s->fp, c, "#");
+		status_printf_ln(s, c, "  (use \"git rm --cached <file>...\" to unstage)");
+	status_printf_ln(s, c, "  (use \"git add/rm <file>...\" as appropriate to mark resolution)");
+	status_printf_ln(s, c, "");
 }
 
 static void wt_status_print_cached_header(struct wt_status *s)
 {
 	const char *c = color(WT_STATUS_HEADER, s);
 
-	color_fprintf_ln(s->fp, c, "# Changes to be committed:");
+	status_printf_ln(s, c, "Changes to be committed:");
 	if (!advice_status_hints)
 		return;
 	if (s->in_merge)
 		; /* NEEDSWORK: use "git reset --unresolve"??? */
 	else if (!s->is_initial)
-		color_fprintf_ln(s->fp, c, "#   (use \"git reset %s <file>...\" to unstage)", s->reference);
+		status_printf_ln(s, c, "  (use \"git reset %s <file>...\" to unstage)", s->reference);
 	else
-		color_fprintf_ln(s->fp, c, "#   (use \"git rm --cached <file>...\" to unstage)");
-	color_fprintf_ln(s->fp, c, "#");
+		status_printf_ln(s, c, "  (use \"git rm --cached <file>...\" to unstage)");
+	status_printf_ln(s, c, "");
 }
 
 static void wt_status_print_dirty_header(struct wt_status *s,
