			if (!removed)
				die_errno("git rm: '%s'", path);
		}
		if (gitmodules_modified)
			stage_updated_gitmodules();
	}
