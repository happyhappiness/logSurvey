			if (cnt < lno)
				break;
			p_mask = 1;
			fputs(line_prefix, stdout);
			if (!(sl->flag & (mark-1))) {
				/*
				 * This sline was here to hang the
