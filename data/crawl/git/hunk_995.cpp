 		return rollback_single_pick();
 	}
 	if (!f)
-		return error_errno(_("cannot open %s"), git_path_head_file());
+		return error_errno(_("cannot open '%s'"), git_path_head_file());
 	if (strbuf_getline_lf(&buf, f)) {
-		error(_("cannot read %s: %s"), git_path_head_file(),
+		error(_("cannot read '%s': %s"), git_path_head_file(),
 		      ferror(f) ?  strerror(errno) : _("unexpected end of file"));
 		fclose(f);
 		goto fail;
