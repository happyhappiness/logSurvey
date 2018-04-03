		}

		printf("%.*s", length, hex);
		if (opt & OUTPUT_ANNOTATE_COMPAT)
			printf("\t(%10s\t%10s\t%d)", ci.author,
			       format_time(ci.author_time, ci.author_tz,
					   show_raw_time),
			       ent->lno + 1 + cnt);
		else {
			if (opt & OUTPUT_SHOW_SCORE)
				printf(" %*d %02d",
				       max_score_digits, ent->score,
