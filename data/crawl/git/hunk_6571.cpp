 	read_next_command();
 
 	/* tagger ... */
-	if (prefixcmp(command_buf.buf, "tagger "))
-		die("Expected tagger command, got %s", command_buf.buf);
-	tagger = parse_ident(command_buf.buf + 7);
+	if (!prefixcmp(command_buf.buf, "tagger ")) {
+		tagger = parse_ident(command_buf.buf + 7);
+		read_next_command();
+	} else
+		tagger = NULL;
 
 	/* tag payload/message */
-	read_next_command();
 	parse_data(&msg);
 
 	/* build the tag object */
 	strbuf_reset(&new_data);
+
 	strbuf_addf(&new_data,
-		"object %s\n"
-		"type %s\n"
-		"tag %s\n"
-		"tagger %s\n"
-		"\n",
-		sha1_to_hex(sha1), commit_type, t->name, tagger);
+		    "object %s\n"
+		    "type %s\n"
+		    "tag %s\n",
+		    sha1_to_hex(sha1), commit_type, t->name);
+	if (tagger)
+		strbuf_addf(&new_data,
+			    "tagger %s\n", tagger);
+	strbuf_addch(&new_data, '\n');
 	strbuf_addbuf(&new_data, &msg);
 	free(tagger);
 
