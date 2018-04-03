		if (only_include_assumed)
			fprintf(fp, "# %s\n", only_include_assumed);

		saved_color_setting = wt_status_use_color;
		wt_status_use_color = 0;
		commitable = run_status(fp, index_file, prefix, 1);
