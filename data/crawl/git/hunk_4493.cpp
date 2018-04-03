 {
 	const char *c = color(WT_STATUS_HEADER, s);
 
-	status_printf_ln(s, c, "Changes not staged for commit:");
+	status_printf_ln(s, c, _("Changes not staged for commit:"));
 	if (!advice_status_hints)
 		return;
 	if (!has_deleted)
-		status_printf_ln(s, c, "  (use \"git add <file>...\" to update what will be committed)");
+		status_printf_ln(s, c, _("  (use \"git add <file>...\" to update what will be committed)"));
 	else
-		status_printf_ln(s, c, "  (use \"git add/rm <file>...\" to update what will be committed)");
-	status_printf_ln(s, c, "  (use \"git checkout -- <file>...\" to discard changes in working directory)");
+		status_printf_ln(s, c, _("  (use \"git add/rm <file>...\" to update what will be committed)"));
+	status_printf_ln(s, c, _("  (use \"git checkout -- <file>...\" to discard changes in working directory)"));
 	if (has_dirty_submodules)
-		status_printf_ln(s, c, "  (commit or discard the untracked or modified content in submodules)");
+		status_printf_ln(s, c, _("  (commit or discard the untracked or modified content in submodules)"));
 	status_printf_ln(s, c, "");
 }
 
