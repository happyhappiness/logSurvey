 		   )
 		die("shallow file was changed during fetch");
 }
+
+struct write_shallow_data {
+	struct strbuf *out;
+	int use_pack_protocol;
+	int count;
+};
+
+static int write_one_shallow(const struct commit_graft *graft, void *cb_data)
+{
+	struct write_shallow_data *data = cb_data;
+	const char *hex = sha1_to_hex(graft->sha1);
+	data->count++;
+	if (data->use_pack_protocol)
+		packet_buf_write(data->out, "shallow %s", hex);
+	else {
+		strbuf_addstr(data->out, hex);
+		strbuf_addch(data->out, '\n');
+	}
+	return 0;
+}
+
+int write_shallow_commits(struct strbuf *out, int use_pack_protocol)
+{
+	struct write_shallow_data data;
+	data.out = out;
+	data.use_pack_protocol = use_pack_protocol;
+	data.count = 0;
+	for_each_commit_graft(write_one_shallow, &data);
+	return data.count;
+}
+
+void setup_alternate_shallow(struct lock_file *shallow_lock,
+			     const char **alternate_shallow_file)
+{
+	struct strbuf sb = STRBUF_INIT;
+	int fd;
+
+	check_shallow_file_for_update();
+	fd = hold_lock_file_for_update(shallow_lock, git_path("shallow"),
+				       LOCK_DIE_ON_ERROR);
+	if (write_shallow_commits(&sb, 0)) {
+		if (write_in_full(fd, sb.buf, sb.len) != sb.len)
+			die_errno("failed to write to %s",
+				  shallow_lock->filename);
+		*alternate_shallow_file = shallow_lock->filename;
+	} else
+		/*
+		 * is_repository_shallow() sees empty string as "no
+		 * shallow file".
+		 */
+		*alternate_shallow_file = "";
+	strbuf_release(&sb);
+}