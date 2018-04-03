 	char *msg = commit->buffer;
 	char *out;
 
+	if (!msg) {
+		enum object_type type;
+		unsigned long size;
+
+		msg = read_sha1_file(commit->object.sha1, &type, &size);
+		if (!msg)
+			die("Cannot read commit object %s",
+			    sha1_to_hex(commit->object.sha1));
+		if (type != OBJ_COMMIT)
+			die("Expected commit for '%s', got %s",
+			    sha1_to_hex(commit->object.sha1), typename(type));
+	}
+
 	if (!output_encoding || !*output_encoding)
 		return msg;
 	encoding = get_header(commit, msg, "encoding");
 	use_encoding = encoding ? encoding : utf8;
-	if (same_encoding(use_encoding, output_encoding))
-		if (encoding) /* we'll strip encoding header later */
-			out = xstrdup(commit->buffer);
-		else
-			return msg; /* nothing to do */
-	else
-		out = reencode_string(commit->buffer,
-				      output_encoding, use_encoding);
+	if (same_encoding(use_encoding, output_encoding)) {
+		/*
+		 * No encoding work to be done. If we have no encoding header
+		 * at all, then there's nothing to do, and we can return the
+		 * message verbatim (whether newly allocated or not).
+		 */
+		if (!encoding)
+			return msg;
+
+		/*
+		 * Otherwise, we still want to munge the encoding header in the
+		 * result, which will be done by modifying the buffer. If we
+		 * are using a fresh copy, we can reuse it. But if we are using
+		 * the cached copy from commit->buffer, we need to duplicate it
+		 * to avoid munging commit->buffer.
+		 */
+		out = msg;
+		if (out == commit->buffer)
+			out = xstrdup(out);
+	}
+	else {
+		/*
+		 * There's actual encoding work to do. Do the reencoding, which
+		 * still leaves the header to be replaced in the next step. At
+		 * this point, we are done with msg. If we allocated a fresh
+		 * copy, we can free it.
+		 */
+		out = reencode_string(msg, output_encoding, use_encoding);
+		if (out && msg != commit->buffer)
+			free(msg);
+	}
+
+	/*
+	 * This replacement actually consumes the buffer we hand it, so we do
+	 * not have to worry about freeing the old "out" here.
+	 */
 	if (out)
 		out = replace_encoding_header(out, output_encoding);
 
