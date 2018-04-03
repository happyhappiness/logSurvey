				last_shown = lno-1;
			}
			if (last_shown && lno != last_shown + 1)
				fputs(hunk_mark, stdout);
			if (!opt->count)
				show_line(opt, bol, eol, name, lno, ':');
			last_shown = last_hit = lno;
