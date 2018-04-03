	/* Update core.worktree setting */
	strbuf_reset(&file_name);
	strbuf_addf(&file_name, "%s/config", git_dir);
	if (git_config_set_in_file(file_name.buf, "core.worktree",
				   relative_path(real_work_tree, git_dir,
						 &rel_path)))
		die(_("Could not set core.worktree in %s"),
		    file_name.buf);

	strbuf_release(&file_name);
	strbuf_release(&rel_path);