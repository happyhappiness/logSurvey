 		else
 			close_pack(p);
 }
+
+/*
+ * The LRU pack is the one with the oldest MRU window, preferring packs
+ * with no used windows, or the oldest mtime if it has no windows allocated.
+ */
+static void find_lru_pack(struct packed_git *p, struct packed_git **lru_p, struct pack_window **mru_w, int *accept_windows_inuse)
+{
+	struct pack_window *w, *this_mru_w;
+	int has_windows_inuse = 0;
+
+	/*
+	 * Reject this pack if it has windows and the previously selected
+	 * one does not.  If this pack does not have windows, reject
+	 * it if the pack file is newer than the previously selected one.
+	 */
+	if (*lru_p && !*mru_w && (p->windows || p->mtime > (*lru_p)->mtime))
+		return;
+
+	for (w = this_mru_w = p->windows; w; w = w->next) {
+		/*
+		 * Reject this pack if any of its windows are in use,
+		 * but the previously selected pack did not have any
+		 * inuse windows.  Otherwise, record that this pack
+		 * has windows in use.
+		 */
+		if (w->inuse_cnt) {
+			if (*accept_windows_inuse)
+				has_windows_inuse = 1;
+			else
+				return;
+		}
+
+		if (w->last_used > this_mru_w->last_used)
+			this_mru_w = w;
+
+		/*
+		 * Reject this pack if it has windows that have been
+		 * used more recently than the previously selected pack.
+		 * If the previously selected pack had windows inuse and
+		 * we have not encountered a window in this pack that is
+		 * inuse, skip this check since we prefer a pack with no
+		 * inuse windows to one that has inuse windows.
+		 */
+		if (*mru_w && *accept_windows_inuse == has_windows_inuse &&
+		    this_mru_w->last_used > (*mru_w)->last_used)
+			return;
+	}
+
+	/*
+	 * Select this pack.
+	 */
+	*mru_w = this_mru_w;
+	*lru_p = p;
+	*accept_windows_inuse = has_windows_inuse;
+}
+
+static int close_one_pack(void)
+{
+	struct packed_git *p, *lru_p = NULL;
+	struct pack_window *mru_w = NULL;
+	int accept_windows_inuse = 1;
+
+	for (p = packed_git; p; p = p->next) {
+		if (p->pack_fd == -1)
+			continue;
+		find_lru_pack(p, &lru_p, &mru_w, &accept_windows_inuse);
+	}
+
+	if (lru_p)
+		return close_pack_fd(lru_p);
+
+	return 0;
+}
+
+static unsigned int get_max_fd_limit(void)
+{
+#ifdef RLIMIT_NOFILE
+	{
+		struct rlimit lim;
+
+		if (!getrlimit(RLIMIT_NOFILE, &lim))
+			return lim.rlim_cur;
+	}
+#endif
+
+#ifdef _SC_OPEN_MAX
+	{
+		long open_max = sysconf(_SC_OPEN_MAX);
+		if (0 < open_max)
+			return open_max;
+		/*
+		 * Otherwise, we got -1 for one of the two
+		 * reasons:
+		 *
+		 * (1) sysconf() did not understand _SC_OPEN_MAX
+		 *     and signaled an error with -1; or
+		 * (2) sysconf() said there is no limit.
+		 *
+		 * We _could_ clear errno before calling sysconf() to
+		 * tell these two cases apart and return a huge number
+		 * in the latter case to let the caller cap it to a
+		 * value that is not so selfish, but letting the
+		 * fallback OPEN_MAX codepath take care of these cases
+		 * is a lot simpler.
+		 */
+	}
+#endif
+
+#ifdef OPEN_MAX
+	return OPEN_MAX;
+#else
+	return 1; /* see the caller ;-) */
+#endif
+}
+
+/*
+ * Do not call this directly as this leaks p->pack_fd on error return;
+ * call open_packed_git() instead.
+ */
+static int open_packed_git_1(struct packed_git *p)
+{
+	struct stat st;
+	struct pack_header hdr;
+	unsigned char sha1[20];
+	unsigned char *idx_sha1;
+	long fd_flag;
+
+	if (!p->index_data && open_pack_index(p))
+		return error("packfile %s index unavailable", p->pack_name);
+
+	if (!pack_max_fds) {
+		unsigned int max_fds = get_max_fd_limit();
+
+		/* Save 3 for stdin/stdout/stderr, 22 for work */
+		if (25 < max_fds)
+			pack_max_fds = max_fds - 25;
+		else
+			pack_max_fds = 1;
+	}
+
+	while (pack_max_fds <= pack_open_fds && close_one_pack())
+		; /* nothing */
+
+	p->pack_fd = git_open(p->pack_name);
+	if (p->pack_fd < 0 || fstat(p->pack_fd, &st))
+		return -1;
+	pack_open_fds++;
+
+	/* If we created the struct before we had the pack we lack size. */
+	if (!p->pack_size) {
+		if (!S_ISREG(st.st_mode))
+			return error("packfile %s not a regular file", p->pack_name);
+		p->pack_size = st.st_size;
+	} else if (p->pack_size != st.st_size)
+		return error("packfile %s size changed", p->pack_name);
+
+	/* We leave these file descriptors open with sliding mmap;
+	 * there is no point keeping them open across exec(), though.
+	 */
+	fd_flag = fcntl(p->pack_fd, F_GETFD, 0);
+	if (fd_flag < 0)
+		return error("cannot determine file descriptor flags");
+	fd_flag |= FD_CLOEXEC;
+	if (fcntl(p->pack_fd, F_SETFD, fd_flag) == -1)
+		return error("cannot set FD_CLOEXEC");
+
+	/* Verify we recognize this pack file format. */
+	if (read_in_full(p->pack_fd, &hdr, sizeof(hdr)) != sizeof(hdr))
+		return error("file %s is far too short to be a packfile", p->pack_name);
+	if (hdr.hdr_signature != htonl(PACK_SIGNATURE))
+		return error("file %s is not a GIT packfile", p->pack_name);
+	if (!pack_version_ok(hdr.hdr_version))
+		return error("packfile %s is version %"PRIu32" and not"
+			" supported (try upgrading GIT to a newer version)",
+			p->pack_name, ntohl(hdr.hdr_version));
+
+	/* Verify the pack matches its index. */
+	if (p->num_objects != ntohl(hdr.hdr_entries))
+		return error("packfile %s claims to have %"PRIu32" objects"
+			     " while index indicates %"PRIu32" objects",
+			     p->pack_name, ntohl(hdr.hdr_entries),
+			     p->num_objects);
+	if (lseek(p->pack_fd, p->pack_size - sizeof(sha1), SEEK_SET) == -1)
+		return error("end of packfile %s is unavailable", p->pack_name);
+	if (read_in_full(p->pack_fd, sha1, sizeof(sha1)) != sizeof(sha1))
+		return error("packfile %s signature is unavailable", p->pack_name);
+	idx_sha1 = ((unsigned char *)p->index_data) + p->index_size - 40;
+	if (hashcmp(sha1, idx_sha1))
+		return error("packfile %s does not match index", p->pack_name);
+	return 0;
+}
+
+int open_packed_git(struct packed_git *p)
+{
+	if (!open_packed_git_1(p))
+		return 0;
+	close_pack_fd(p);
+	return -1;
+}
+
+static int in_window(struct pack_window *win, off_t offset)
+{
+	/* We must promise at least 20 bytes (one hash) after the
+	 * offset is available from this window, otherwise the offset
+	 * is not actually in this window and a different window (which
+	 * has that one hash excess) must be used.  This is to support
+	 * the object header and delta base parsing routines below.
+	 */
+	off_t win_off = win->offset;
+	return win_off <= offset
+		&& (offset + 20) <= (win_off + win->len);
+}
+
+unsigned char *use_pack(struct packed_git *p,
+		struct pack_window **w_cursor,
+		off_t offset,
+		unsigned long *left)
+{
+	struct pack_window *win = *w_cursor;
+
+	/* Since packfiles end in a hash of their content and it's
+	 * pointless to ask for an offset into the middle of that
+	 * hash, and the in_window function above wouldn't match
+	 * don't allow an offset too close to the end of the file.
+	 */
+	if (!p->pack_size && p->pack_fd == -1 && open_packed_git(p))
+		die("packfile %s cannot be accessed", p->pack_name);
+	if (offset > (p->pack_size - 20))
+		die("offset beyond end of packfile (truncated pack?)");
+	if (offset < 0)
+		die(_("offset before end of packfile (broken .idx?)"));
+
+	if (!win || !in_window(win, offset)) {
+		if (win)
+			win->inuse_cnt--;
+		for (win = p->windows; win; win = win->next) {
+			if (in_window(win, offset))
+				break;
+		}
+		if (!win) {
+			size_t window_align = packed_git_window_size / 2;
+			off_t len;
+
+			if (p->pack_fd == -1 && open_packed_git(p))
+				die("packfile %s cannot be accessed", p->pack_name);
+
+			win = xcalloc(1, sizeof(*win));
+			win->offset = (offset / window_align) * window_align;
+			len = p->pack_size - win->offset;
+			if (len > packed_git_window_size)
+				len = packed_git_window_size;
+			win->len = (size_t)len;
+			pack_mapped += win->len;
+			while (packed_git_limit < pack_mapped
+				&& unuse_one_window(p))
+				; /* nothing */
+			win->base = xmmap(NULL, win->len,
+				PROT_READ, MAP_PRIVATE,
+				p->pack_fd, win->offset);
+			if (win->base == MAP_FAILED)
+				die_errno("packfile %s cannot be mapped",
+					  p->pack_name);
+			if (!win->offset && win->len == p->pack_size
+				&& !p->do_not_close)
+				close_pack_fd(p);
+			pack_mmap_calls++;
+			pack_open_windows++;
+			if (pack_mapped > peak_pack_mapped)
+				peak_pack_mapped = pack_mapped;
+			if (pack_open_windows > peak_pack_open_windows)
+				peak_pack_open_windows = pack_open_windows;
+			win->next = p->windows;
+			p->windows = win;
+		}
+	}
+	if (win != *w_cursor) {
+		win->last_used = pack_used_ctr++;
+		win->inuse_cnt++;
+		*w_cursor = win;
+	}
+	offset -= win->offset;
+	if (left)
+		*left = win->len - xsize_t(offset);
+	return win->base + offset;
+}
