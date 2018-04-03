			free(refname);
		}
		else
			create_branch(opts->new_branch, new_branch_info->name,
				      opts->new_branch_force ? 1 : 0,
				      opts->new_branch_force ? 1 : 0,
				      opts->new_branch_log,
				      opts->quiet,
				      opts->track);
		new_branch_info->name = opts->new_branch;
		setup_branch_path(new_branch_info);
	}

	old_desc = old_branch_info->name;
	if (!old_desc && old_branch_info->commit)
		old_desc = oid_to_hex(&old_branch_info->commit->object.oid);

	reflog_msg = getenv("GIT_REFLOG_ACTION");
	if (!reflog_msg)
		strbuf_addf(&msg, "checkout: moving from %s to %s",
			old_desc ? old_desc : "(invalid)", new_branch_info->name);
	else
		strbuf_insert(&msg, 0, reflog_msg, strlen(reflog_msg));

	if (!strcmp(new_branch_info->name, "HEAD") && !new_branch_info->path && !opts->force_detach) {
		/* Nothing to do. */
	} else if (opts->force_detach || !new_branch_info->path) {	/* No longer on any branch. */
		update_ref(msg.buf, "HEAD", &new_branch_info->commit->object.oid, NULL,
			   REF_NO_DEREF, UPDATE_REFS_DIE_ON_ERR);
		if (!opts->quiet) {
			if (old_branch_info->path &&
			    advice_detached_head && !opts->force_detach)
				detach_advice(new_branch_info->name);
			describe_detached_head(_("HEAD is now at"), new_branch_info->commit);
		}
	} else if (new_branch_info->path) {	/* Switch branches. */
		if (create_symref("HEAD", new_branch_info->path, msg.buf) < 0)
			die(_("unable to update HEAD"));
		if (!opts->quiet) {
			if (old_branch_info->path && !strcmp(new_branch_info->path, old_branch_info->path)) {
				if (opts->new_branch_force)
					fprintf(stderr, _("Reset branch '%s'\n"),
						new_branch_info->name);
				else
					fprintf(stderr, _("Already on '%s'\n"),
						new_branch_info->name);
			} else if (opts->new_branch) {
				if (opts->branch_exists)
					fprintf(stderr, _("Switched to and reset branch '%s'\n"), new_branch_info->name);
				else
					fprintf(stderr, _("Switched to a new branch '%s'\n"), new_branch_info->name);
			} else {
				fprintf(stderr, _("Switched to branch '%s'\n"),
					new_branch_info->name);
			}
		}
		if (old_branch_info->path && old_branch_info->name) {
			if (!ref_exists(old_branch_info->path) && reflog_exists(old_branch_info->path))
				delete_reflog(old_branch_info->path);
		}
	}
	remove_branch_state();
	strbuf_release(&msg);
	if (!opts->quiet &&
	    (new_branch_info->path || (!opts->force_detach && !strcmp(new_branch_info->name, "HEAD"))))
		report_tracking(new_branch_info);
}

static int add_pending_uninteresting_ref(const char *refname,
