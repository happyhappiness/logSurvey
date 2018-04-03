 		if (!win) {
 			size_t window_align = packed_git_window_size / 2;
 			off_t len;
+
+			if (p->pack_fd == -1 && open_packed_git(p))
+				die("packfile %s cannot be accessed", p->pack_name);
+
 			win = xcalloc(1, sizeof(*win));
 			win->offset = (offset / window_align) * window_align;
 			len = p->pack_size - win->offset;
