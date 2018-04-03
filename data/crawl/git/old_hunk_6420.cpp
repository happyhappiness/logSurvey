	}

	if (!path) {
		logerror("'%s': unable to chdir or not a git archive", dir);
		return NULL;
	}

