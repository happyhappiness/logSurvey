				       ent->s_lno + 1 + cnt);

			if (!(opt & OUTPUT_NO_AUTHOR)) {
				const char *name;
				int pad;
				if (opt & OUTPUT_SHOW_EMAIL)
					name = ci.author_mail;
				else
					name = ci.author;
				pad = longest_author - utf8_strwidth(name);
				printf(" (%s%*s %10s",
				       name, pad, "",
				       format_time(ci.author_time,
						   ci.author_tz,
						   show_raw_time));
