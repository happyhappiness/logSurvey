 					struct wt_status_state *state,
 					const char *color)
 {
-	status_printf_ln(s, color, _("You are currently reverting a commit."));
+	status_printf_ln(s, color, _("You are currently reverting commit %s."),
+			 find_unique_abbrev(state->revert_head_sha1, DEFAULT_ABBREV));
 	if (advice_status_hints) {
 		if (has_unmerged(s))
 			status_printf_ln(s, color,
