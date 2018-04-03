		if (key == keys.svn_fs_dump_format_version) {
			dump_ctx.version = atoi(val);
			if (dump_ctx.version > 2)
				die("expected svn dump format version <= 2, found %d",
				    dump_ctx.version);
		} else if (key == keys.uuid) {
			dump_ctx.uuid = pool_intern(val);