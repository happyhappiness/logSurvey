 	return split_in_progress;
 }
 
+static void print_rebase_state(struct wt_status *s,
+				struct wt_status_state *state,
+				const char *color)
+{
+	if (state->branch)
+		status_printf_ln(s, color,
+				 _("You are currently rebasing branch '%s' on '%s'."),
+				 state->branch,
+				 state->onto);
+	else
+		status_printf_ln(s, color,
+				 _("You are currently rebasing."));
+}
+
 static void show_rebase_in_progress(struct wt_status *s,
 				struct wt_status_state *state,
 				const char *color)
 {
 	struct stat st;
 
 	if (has_unmerged(s)) {
-		if (state->branch)
-			status_printf_ln(s, color,
-					 _("You are currently rebasing branch '%s' on '%s'."),
-					 state->branch,
-					 state->onto);
-		else
-			status_printf_ln(s, color,
-					 _("You are currently rebasing."));
+		print_rebase_state(s, state, color);
 		if (s->hints) {
 			status_printf_ln(s, color,
 				_("  (fix conflicts and then run \"git rebase --continue\")"));
