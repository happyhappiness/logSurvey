		usage_with_options(builtin_merge_usage,
			builtin_merge_options);

	if (verify_signatures) {
		for (p = remoteheads; p; p = p->next) {
			struct commit *commit = p->item;
			char hex[41];
			struct signature_check signature_check;
			memset(&signature_check, 0, sizeof(signature_check));

			check_commit_signature(commit, &signature_check);

			strcpy(hex, find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV));
			switch (signature_check.result) {
			case 'G':
				break;
			case 'B':
				die(_("Commit %s has a bad GPG signature "
				      "allegedly by %s."), hex, signature_check.signer);
			default: /* 'N' */
				die(_("Commit %s does not have a GPG signature."), hex);
			}
			if (verbosity >= 0 && signature_check.result == 'G')
				printf(_("Commit %s has a good GPG signature by %s\n"),
				       hex, signature_check.signer);

			free(signature_check.gpg_output);
			free(signature_check.gpg_status);
			free(signature_check.signer);
			free(signature_check.key);
		}
	}

	strbuf_addstr(&buf, "merge");
	for (p = remoteheads; p; p = p->next)
		strbuf_addf(&buf, " %s", merge_remote_util(p->item)->name);
