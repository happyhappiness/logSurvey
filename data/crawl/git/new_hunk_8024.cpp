	SHA1_Final(pack_file_sha1, &c);
	write_or_die(pack_fd, pack_file_sha1, 20);
}

char *index_pack_lockfile(int ip_out)
{
	int len, s;
	char packname[46];

	/*
	 * The first thing we expects from index-pack's output
	 * is "pack\t%40s\n" or "keep\t%40s\n" (46 bytes) where
	 * %40s is the newly created pack SHA1 name.  In the "keep"
	 * case, we need it to remove the corresponding .keep file
	 * later on.  If we don't get that then tough luck with it.
	 */
	for (len = 0;
		 len < 46 && (s = xread(ip_out, packname+len, 46-len)) > 0;
		 len += s);
	if (len == 46 && packname[45] == '\n' &&
		memcmp(packname, "keep\t", 5) == 0) {
		char path[PATH_MAX];
		packname[45] = 0;
		snprintf(path, sizeof(path), "%s/pack/pack-%s.keep",
			 get_object_directory(), packname + 5);
		return xstrdup(path);
	}
	return NULL;
}
