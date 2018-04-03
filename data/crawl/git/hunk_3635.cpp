 	return strcmp(a->name, b->name);
 }
 
+static void setup_alternate_shallow(void)
+{
+	struct strbuf sb = STRBUF_INIT;
+	int fd;
+
+	check_shallow_file_for_update();
+	fd = hold_lock_file_for_update(&shallow_lock, git_path("shallow"),
+				       LOCK_DIE_ON_ERROR);
+	if (write_shallow_commits(&sb, 0)) {
+		if (write_in_full(fd, sb.buf, sb.len) != sb.len)
+			die_errno("failed to write to %s", shallow_lock.filename);
+		alternate_shallow_file = shallow_lock.filename;
+	} else
+		/*
+		 * is_repository_shallow() sees empty string as "no
+		 * shallow file".
+		 */
+		alternate_shallow_file = "";
+	strbuf_release(&sb);
+}
+
 static struct ref *do_fetch_pack(struct fetch_pack_args *args,
 				 int fd[2],
 				 const struct ref *orig_ref,
