					from = lno - opt->pre_context;
				else
					from = 1;
				if (from <= opt->last_shown)
					from = opt->last_shown + 1;
				while (from < lno) {
					pcl = &prev[lno-from-1];
					show_line(opt, pcl->bol, pcl->eol,
						  name, from, '-');
					from++;
				}
			}
			if (!opt->count)
				show_line(opt, bol, eol, name, lno, ':');
			last_hit = lno;
		}
		else if (last_hit &&
			 lno <= last_hit + opt->post_context) {
			/* If the last hit is within the post context,
			 * we need to show this line.
			 */
			show_line(opt, bol, eol, name, lno, '-');
		}
		if (opt->pre_context) {
			memmove(prev+1, prev,
