	/* Update core.worktree setting */
	strbuf_reset(&file_name);
	strbuf_addf(&file_name, "%s/config", git_dir);
	git_config_set_in_file_or_die(file_name.buf, "core.worktree",
				      relative_path(real_work_tree, git_dir,
						    &rel_path));

	strbuf_release(&file_name);
	strbuf_release(&rel_path);