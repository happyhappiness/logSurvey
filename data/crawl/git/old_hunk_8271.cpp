		if (p->score) {
			char *name = quote_one(p->two->path);
			printf(" rewrite %s (%d%%)\n", name,
				(int)(0.5 + p->score * 100.0/MAX_SCORE));
			free(name);
			show_mode_change(p, 0);
		} else	show_mode_change(p, 1);