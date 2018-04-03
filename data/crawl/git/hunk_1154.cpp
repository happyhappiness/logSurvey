 	else {
 		o = get_origin(&sb, sb.final, path);
 		if (fill_blob_sha1_and_mode(o))
-			die("no such path %s in %s", path, final_commit_name);
+			die(_("no such path %s in %s"), path, final_commit_name);
 
 		if (DIFF_OPT_TST(&sb.revs->diffopt, ALLOW_TEXTCONV) &&
 		    textconv_object(path, o->mode, o->blob_sha1, 1, (char **) &sb.final_buf,
