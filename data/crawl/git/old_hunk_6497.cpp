				printf(" %*d", max_orig_digits,
				       ent->s_lno + 1 + cnt);

			if (!(opt & OUTPUT_NO_AUTHOR))
				printf(" (%-*.*s %10s",
				       longest_author, longest_author,
				       ci.author,
				       format_time(ci.author_time,
						   ci.author_tz,
						   show_raw_time));
			printf(" %*d) ",
			       max_digits, ent->lno + 1 + cnt);
		}
