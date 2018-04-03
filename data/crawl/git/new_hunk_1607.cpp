			status_printf_ln(s, color,
				_("  (use \"git commit\" to conclude merge)"));
	}
	wt_longstatus_print_trailer(s);
}

static void show_am_in_progress(struct wt_status *s,
