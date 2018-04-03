		template_dir = system_path(DEFAULT_GIT_TEMPLATE_DIR);
	if (!template_dir[0])
		return;
	template_len = strlen(template_dir);
	if (PATH_MAX <= (template_len+strlen("/config")))
		die("insanely long template path %s", template_dir);
	strcpy(template_path, template_dir);
	if (template_path[template_len-1] != '/') {
		template_path[template_len++] = '/';
		template_path[template_len] = 0;
