 			config_error_nonbool(k);
 		c->combine = parse_combine_notes_fn(v);
 		if (!c->combine) {
-			error("Bad notes.rewriteMode value: '%s'", v);
+			error(_("Bad notes.rewriteMode value: '%s'"), v);
 			return 1;
 		}
 		return 0;
