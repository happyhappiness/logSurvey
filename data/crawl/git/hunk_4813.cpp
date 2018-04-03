 	if (!p->index_data && open_pack_index(p))
 		return error("packfile %s index unavailable", p->pack_name);
 
+	if (!pack_max_fds) {
+		struct rlimit lim;
+		unsigned int max_fds;
+
+		if (getrlimit(RLIMIT_NOFILE, &lim))
+			die_errno("cannot get RLIMIT_NOFILE");
+
+		max_fds = lim.rlim_cur;
+
+		/* Save 3 for stdin/stdout/stderr, 22 for work */
+		if (25 < max_fds)
+			pack_max_fds = max_fds - 25;
+		else
+			pack_max_fds = 1;
+	}
+
+	while (pack_max_fds <= pack_open_fds && unuse_one_window(NULL, -1))
+		; /* nothing */
+
 	p->pack_fd = git_open_noatime(p->pack_name, p);
 	if (p->pack_fd < 0 || fstat(p->pack_fd, &st))
 		return -1;
+	pack_open_fds++;
 
 	/* If we created the struct before we had the pack we lack size. */
 	if (!p->pack_size) {
