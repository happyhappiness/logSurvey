 		status_printf_ln(s, color,
 			_("  (use \"git revert --abort\" to cancel the revert operation)"));
 	}
-	wt_status_print_trailer(s);
+	wt_longstatus_print_trailer(s);
 }
 
 static void show_bisect_in_progress(struct wt_status *s,
