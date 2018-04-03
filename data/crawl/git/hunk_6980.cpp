 		p = uq.buf;
 	}
 
-	if (inline_data) {
+	if (S_ISGITLINK(mode)) {
+		if (inline_data)
+			die("Git links cannot be specified 'inline': %s",
+				command_buf.buf);
+		else if (oe) {
+			if (oe->type != OBJ_COMMIT)
+				die("Not a commit (actually a %s): %s",
+					typename(oe->type), command_buf.buf);
+		}
+		/*
+		 * Accept the sha1 without checking; it expected to be in
+		 * another repository.
+		 */
+	} else if (inline_data) {
 		static struct strbuf buf = STRBUF_INIT;
 
 		if (p != uq.buf) {
