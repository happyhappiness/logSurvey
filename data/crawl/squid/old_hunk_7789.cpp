    aclDestroyAccessList(&ICPAccessList);

    if ((fp = fopen(file_name, "r")) == NULL) {
	sprintf(fatal_str, "Unable to open configuration file: %s", file_name);
	fatal(fatal_str);
    }
    cfg_filename = file_name;
