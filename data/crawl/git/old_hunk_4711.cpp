			       find_unique_abbrev(sha1, DEFAULT_ABBREV));
			strbuf_addf(&buf, "branch.%s", bname.buf);
			if (git_config_rename_section(buf.buf, NULL) < 0)
				warning("Update of config-file failed");
			strbuf_release(&buf);
		}
	}
