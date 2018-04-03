	struct strbuf msg = STRBUF_INIT;
	const char *old_desc;
	if (opts->new_branch) {
		if (opts->new_orphan_branch) {
			if (opts->new_branch_log && !log_all_ref_updates) {
				int temp;
				char *log_file;
				char *ref_name = mkpath("refs/heads/%s", opts->new_orphan_branch);

				temp = log_all_ref_updates;
				log_all_ref_updates = 1;
				if (log_ref_setup(ref_name, &log_file)) {
					fprintf(stderr, "Can not do reflog for '%s'\n",
					    opts->new_orphan_branch);
					log_all_ref_updates = temp;
					return;
				}
				log_all_ref_updates = temp;
			}
		}
		else
			create_branch(old->name, opts->new_branch, new->name, 0,
				      opts->new_branch_log, opts->track);
		new->name = opts->new_branch;
