		if (permille) {
			int percent = permille / 10;
			if (percent >= dir->percent) {
				fprintf(opt->file, "%s%4d.%01d%% %.*s\n", line_prefix,
					percent, permille % 10, baselen, base);
				if (!dir->cumulative)
					return 0;
			}
