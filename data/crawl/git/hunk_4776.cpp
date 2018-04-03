 			branch_status_color = color(WT_STATUS_NOBRANCH, s);
 			on_what = "Not currently on any branch.";
 		}
-		color_fprintf(s->fp, color(WT_STATUS_HEADER, s), "# ");
-		color_fprintf(s->fp, branch_status_color, "%s", on_what);
-		color_fprintf_ln(s->fp, branch_color, "%s", branch_name);
+		status_printf(s, color(WT_STATUS_HEADER, s), "");
+		status_printf_more(s, branch_status_color, "%s", on_what);
+		status_printf_more(s, branch_color, "%s\n", branch_name);
 		if (!s->is_initial)
 			wt_status_print_tracking(s);
 	}
 
 	if (s->is_initial) {
-		color_fprintf_ln(s->fp, color(WT_STATUS_HEADER, s), "#");
-		color_fprintf_ln(s->fp, color(WT_STATUS_HEADER, s), "# Initial commit");
-		color_fprintf_ln(s->fp, color(WT_STATUS_HEADER, s), "#");
+		status_printf_ln(s, color(WT_STATUS_HEADER, s), "");
+		status_printf_ln(s, color(WT_STATUS_HEADER, s), "Initial commit");
+		status_printf_ln(s, color(WT_STATUS_HEADER, s), "");
 	}
 
 	wt_status_print_updated(s);
