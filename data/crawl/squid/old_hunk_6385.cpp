    char *tmp_line;
    free_all();
    default_all();
    if ((fp = fopen(file_name, "r")) == NULL) {
	snprintf(fatal_str, BUFSIZ, "Unable to open configuration file: %s: %s",
	    file_name, xstrerror());
	fatal(fatal_str);
    }
    cfg_filename = file_name;
    if ((token = strrchr(cfg_filename, '/')))
	cfg_filename = token + 1;
