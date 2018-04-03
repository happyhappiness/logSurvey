	if (only_include_assumed)
		fprintf(fp, "# %s\n", only_include_assumed);

	commitable = run_status(fp, index_file);

	fclose(fp);

