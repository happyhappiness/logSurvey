		exit_status = 1;
	}

	for (i = 0; i < dir->nr; i++) {
		check_embedded_repo(dir->entries[i]->name);
		if (add_file_to_index(&the_index, dir->entries[i]->name, flags)) {
			if (!ignore_add_errors)
				die(_("adding files failed"));
			exit_status = 1;
		}
	}
	return exit_status;
}

