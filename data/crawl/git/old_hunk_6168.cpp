	}
	dir = opendir(template_path);
	if (!dir) {
		fprintf(stderr, "warning: templates not found %s\n",
			template_dir);
		return;
	}

