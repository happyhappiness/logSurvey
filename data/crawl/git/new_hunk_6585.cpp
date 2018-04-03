			ret = 1;
		} else {
			struct strbuf buf = STRBUF_INIT;
			printf("Deleted %sbranch %s (%s).\n", remote, argv[i],
				find_unique_abbrev(sha1, DEFAULT_ABBREV));
			strbuf_addf(&buf, "branch.%s", argv[i]);
			if (git_config_rename_section(buf.buf, NULL) < 0)
				warning("Update of config-file failed");
