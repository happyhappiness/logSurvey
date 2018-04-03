			 * we need to show this line.
			 */
			if (last_shown && lno != last_shown + 1)
				fputs(hunk_mark, stdout);
			show_line(opt, bol, eol, name, lno, '-');
			last_shown = lno;
		}
