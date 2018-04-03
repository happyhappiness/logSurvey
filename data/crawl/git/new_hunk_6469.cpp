		if (!force &&
		    !in_merge_bases(rev, &head_rev, 1)) {
			error("The branch '%s' is not an ancestor of "
			      "your current HEAD.\n"
			      "If you are sure you want to delete it, "
			      "run 'git branch -D %s'.", bname.buf, bname.buf);
			ret = 1;
			continue;
		}

		if (delete_ref(name, sha1, 0)) {
			error("Error deleting %sbranch '%s'", remote,
			      bname.buf);
			ret = 1;
		} else {
			struct strbuf buf = STRBUF_INIT;
			printf("Deleted %sbranch %s (%s).\n", remote,
			       bname.buf,
			       find_unique_abbrev(sha1, DEFAULT_ABBREV));
			strbuf_addf(&buf, "branch.%s", bname.buf);
			if (git_config_rename_section(buf.buf, NULL) < 0)
				warning("Update of config-file failed");
			strbuf_release(&buf);
