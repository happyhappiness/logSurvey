			int j;
			unsigned long p_mask;
			struct sline *sl = &sline[lno++];
			ll = (sl->flag & no_pre_delete) ? NULL : sl->lost;
			while (ll) {
				printf("%s%s", line_prefix, c_old);
				for (j = 0; j < num_parent; j++) {
