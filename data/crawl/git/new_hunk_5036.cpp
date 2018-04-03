					"warning: Log for '%.*s' only goes "
					"back to %s.\n", len, str,
					show_date(co_time, co_tz, DATE_RFC2822));
			else {
				free(real_ref);
				die("Log for '%.*s' only has %d entries.",
				    len, str, co_cnt);
			}
		}
	}
