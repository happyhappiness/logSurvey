			      bname.buf);
			ret = 1;
		} else {
			struct strbuf buf = STRBUF_INIT;
			if (!quiet)
				printf(remote_branch
				       ? _("Deleted remote branch %s (was %s).\n")
				       : _("Deleted branch %s (was %s).\n"),
				       bname.buf,
				       find_unique_abbrev(sha1, DEFAULT_ABBREV));
			strbuf_addf(&buf, "branch.%s", bname.buf);
			if (git_config_rename_section(buf.buf, NULL) < 0)
				warning(_("Update of config-file failed"));
			strbuf_release(&buf);
		}
	}
