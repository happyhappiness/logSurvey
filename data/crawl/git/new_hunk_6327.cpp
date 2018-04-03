	}
	dir = opendir(template_path);
	if (!dir) {
		warning("templates not found %s", template_dir);
		return;
	}

