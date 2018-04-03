
	/* Make sure that template is from the correct vintage */
	strbuf_addstr(&template_path, "config");
	repository_format_version = 0;
	git_config_from_file(check_repository_format_version,
			     template_path.buf, NULL);
	strbuf_setlen(&template_path, template_len);

	if (repository_format_version &&
	    repository_format_version != GIT_REPO_VERSION) {
		warning(_("not copying templates of "
			"a wrong format version %d from '%s'"),
			repository_format_version,
			template_dir);
		goto close_free_return;
	}
