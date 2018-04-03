				if (!(flags & GET_SHA1_QUIETLY)) {
					warning("Log for '%.*s' only goes "
						"back to %s.", len, str,
						show_date(co_time, co_tz, DATE_MODE(RFC2822)));
				}
			} else {
				if (flags & GET_SHA1_QUIETLY) {
