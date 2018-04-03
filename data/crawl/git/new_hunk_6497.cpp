				printf(" %*d", max_orig_digits,
				       ent->s_lno + 1 + cnt);

			if (!(opt & OUTPUT_NO_AUTHOR)) {
				int pad = longest_author - utf8_strwidth(ci.author);
				printf(" (%s%*s %10s",
				       ci.author, pad, "",
				       format_time(ci.author_time,
						   ci.author_tz,
						   show_raw_time));
			}
			printf(" %*d) ",
			       max_digits, ent->lno + 1 + cnt);
		}
