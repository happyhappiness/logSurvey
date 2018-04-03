 	if (fd < 0)
 		die_errno(_("Could not open '%s' for writing"), filename);
 	strbuf_reset(&buf);
-	if (!allow_fast_forward)
+	if (fast_forward == FF_NO)
 		strbuf_addf(&buf, "no-ff");
 	if (write_in_full(fd, buf.buf, buf.len) != buf.len)
 		die_errno(_("Could not write to '%s'"), filename);
