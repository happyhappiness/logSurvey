 
 	ac = parse_options(ac, av, option, mktree_usage, 0);
 
-	while (strbuf_getline(&sb, stdin, line_termination) != EOF) {
-		char *ptr, *ntr;
-		unsigned mode;
-		enum object_type type;
-		char *path;
-
-		ptr = sb.buf;
-		/*
-		 * Read non-recursive ls-tree output format:
-		 *     mode SP type SP sha1 TAB name
-		 */
-		mode = strtoul(ptr, &ntr, 8);
-		if (ptr == ntr || !ntr || *ntr != ' ')
-			die("input format error: %s", sb.buf);
-		ptr = ntr + 1; /* type */
-		ntr = strchr(ptr, ' ');
-		if (!ntr || sb.buf + sb.len <= ntr + 40 ||
-		    ntr[41] != '\t' ||
-		    get_sha1_hex(ntr + 1, sha1))
-			die("input format error: %s", sb.buf);
-		type = sha1_object_info(sha1, NULL);
-		if (type < 0)
-			die("object %s unavailable", sha1_to_hex(sha1));
-		*ntr++ = 0; /* now at the beginning of SHA1 */
-		if (type != type_from_string(ptr))
-			die("object type %s mismatch (%s)", ptr, typename(type));
-
-		path = ntr + 41;  /* at the beginning of name */
-		if (line_termination && path[0] == '"') {
-			strbuf_reset(&p_uq);
-			if (unquote_c_style(&p_uq, path, NULL)) {
-				die("invalid quoting");
-			}
-			path = p_uq.buf;
-		}
-
-		append_to_tree(mode, sha1, path);
-	}
-	strbuf_release(&p_uq);
+	while (strbuf_getline(&sb, stdin, line_termination) != EOF)
+		mktree_line(sb.buf, sb.len, line_termination);
+
 	strbuf_release(&sb);
 
 	write_tree(sha1);