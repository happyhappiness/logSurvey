		if (read_ref_at(real_ref, at_time, nth, sha1, NULL,
				&co_time, &co_tz, &co_cnt)) {
			if (at_time)
				warning("Log for '%.*s' only goes "
					"back to %s.", len, str,
					show_date(co_time, co_tz, DATE_RFC2822));
			else {
				free(real_ref);