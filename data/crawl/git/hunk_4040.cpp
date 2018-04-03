 	fflush(stdout);
 }
 
+/* NOTE: 'ref' refers to a git reference, while 'rev' refers to a svn revision. */
+static char *read_ref_note(const unsigned char sha1[20])
+{
+	const unsigned char *note_sha1;
+	char *msg = NULL;
+	unsigned long msglen;
+	enum object_type type;
+
+	init_notes(NULL, notes_ref, NULL, 0);
+	if (!(note_sha1 = get_note(NULL, sha1)))
+		return NULL;	/* note tree not found */
+	if (!(msg = read_sha1_file(note_sha1, &type, &msglen)))
+		error("Empty notes tree. %s", notes_ref);
+	else if (!msglen || type != OBJ_BLOB) {
+		error("Note contains unusable content. "
+			"Is something else using this notes tree? %s", notes_ref);
+		free(msg);
+		msg = NULL;
+	}
+	free_notes(NULL);
+	return msg;
+}
+
+static int parse_rev_note(const char *msg, struct rev_note *res)
+{
+	const char *key, *value, *end;
+	size_t len;
+
+	while (*msg) {
+		end = strchr(msg, '\n');
+		len = end ? end - msg : strlen(msg);
+
+		key = "Revision-number: ";
+		if (!prefixcmp(msg, key)) {
+			long i;
+			char *end;
+			value = msg + strlen(key);
+			i = strtol(value, &end, 0);
+			if (end == value || i < 0 || i > UINT32_MAX)
+				return -1;
+			res->rev_nr = i;
+		}
+		msg += len + 1;
+	}
+	return 0;
+}
+
 static int cmd_import(const char *line)
 {
 	int code;
 	int dumpin_fd;
-	unsigned int startrev = 0;
+	char *note_msg;
+	unsigned char head_sha1[20];
+	unsigned int startrev;
 	struct argv_array svndump_argv = ARGV_ARRAY_INIT;
 	struct child_process svndump_proc;
 
+	if (read_ref(private_ref, head_sha1))
+		startrev = 0;
+	else {
+		note_msg = read_ref_note(head_sha1);
+		if(note_msg == NULL) {
+			warning("No note found for %s.", private_ref);
+			startrev = 0;
+		} else {
+			struct rev_note note = { 0 };
+			if (parse_rev_note(note_msg, &note))
+				die("Revision number couldn't be parsed from note.");
+			startrev = note.rev_nr + 1;
+			free(note_msg);
+		}
+	}
+
 	if (dump_from_file) {
 		dumpin_fd = open(url, O_RDONLY);
 		if(dumpin_fd < 0)
