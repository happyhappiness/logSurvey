 	struct strbuf sb = STRBUF_INIT;
 	struct object_id oid;
 
-	if (!(fp = fopen(filename, "r")))
-		die_errno(_("could not open '%s' for reading"), filename);
+	fp = xfopen(filename, "r");
 	while (strbuf_getline_lf(&sb, fp) != EOF) {
 		if (get_oid_hex(sb.buf, &oid))
 			continue;  /* invalid line: does not start with SHA1 */
