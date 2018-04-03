 		return rollback_single_pick();
 	}
 	if (!f)
-		return error(_("cannot open %s: %s"), filename,
+		return error(_("cannot open %s: %s"), git_path_head_file(),
 						strerror(errno));
 	if (strbuf_getline(&buf, f, '\n')) {
-		error(_("cannot read %s: %s"), filename, ferror(f) ?
-			strerror(errno) : _("unexpected end of file"));
+		error(_("cannot read %s: %s"), git_path_head_file(),
+		      ferror(f) ?  strerror(errno) : _("unexpected end of file"));
 		fclose(f);
 		goto fail;
 	}
 	fclose(f);
 	if (get_sha1_hex(buf.buf, sha1) || buf.buf[40] != '\0') {
 		error(_("stored pre-cherry-pick HEAD file '%s' is corrupt"),
-			filename);
+			git_path_head_file());
 		goto fail;
 	}
 	if (reset_for_rollback(sha1))
