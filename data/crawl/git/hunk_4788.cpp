 {
 	const char *c = color(WT_STATUS_HEADER, s);
 
-	color_fprintf_ln(s->fp, c, "# Changes not staged for commit:");
+	status_printf_ln(s, c, "Changes not staged for commit:");
 	if (!advice_status_hints)
 		return;
 	if (!has_deleted)
-		color_fprintf_ln(s->fp, c, "#   (use \"git add <file>...\" to update what will be committed)");
+		status_printf_ln(s, c, "  (use \"git add <file>...\" to update what will be committed)");
 	else
-		color_fprintf_ln(s->fp, c, "#   (use \"git add/rm <file>...\" to update what will be committed)");
-	color_fprintf_ln(s->fp, c, "#   (use \"git checkout -- <file>...\" to discard changes in working directory)");
+		status_printf_ln(s, c, "  (use \"git add/rm <file>...\" to update what will be committed)");
+	status_printf_ln(s, c, "  (use \"git checkout -- <file>...\" to discard changes in working directory)");
 	if (has_dirty_submodules)
-		color_fprintf_ln(s->fp, c, "#   (commit or discard the untracked or modified content in submodules)");
-	color_fprintf_ln(s->fp, c, "#");
+		status_printf_ln(s, c, "  (commit or discard the untracked or modified content in submodules)");
+	status_printf_ln(s, c, "");
 }
 
 static void wt_status_print_other_header(struct wt_status *s,
 					 const char *what,
 					 const char *how)
 {
 	const char *c = color(WT_STATUS_HEADER, s);
-	color_fprintf_ln(s->fp, c, "# %s files:", what);
+	status_printf_ln(s, c, "%s files:", what);
 	if (!advice_status_hints)
 		return;
-	color_fprintf_ln(s->fp, c, "#   (use \"git %s <file>...\" to include in what will be committed)", how);
-	color_fprintf_ln(s->fp, c, "#");
+	status_printf_ln(s, c, "  (use \"git %s <file>...\" to include in what will be committed)", how);
+	status_printf_ln(s, c, "");
 }
 
 static void wt_status_print_trailer(struct wt_status *s)
 {
-	color_fprintf_ln(s->fp, color(WT_STATUS_HEADER, s), "#");
+	status_printf_ln(s, color(WT_STATUS_HEADER, s), "");
 }
 
 #define quote_path quote_path_relative
