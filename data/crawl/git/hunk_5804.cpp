 	char *buf;
 	const char *tagger, *tagger_end, *message;
 	size_t message_size = 0;
+	struct object *tagged;
+
+	/* Trees have no identifer in fast-export output, thus we have no way
+	 * to output tags of trees, tags of tags of trees, etc.  Simply omit
+	 * such tags.
+	 */
+	tagged = tag->tagged;
+	while (tagged->type == OBJ_TAG) {
+		tagged = ((struct tag *)tagged)->tagged;
+	}
+	if (tagged->type == OBJ_TREE) {
+		warning("Omitting tag %s,\nsince tags of trees (or tags of tags of trees, etc.) are not supported.",
+			sha1_to_hex(tag->object.sha1));
+		return;
+	}
 
 	buf = read_sha1_file(tag->object.sha1, &type, &size);
 	if (!buf)
