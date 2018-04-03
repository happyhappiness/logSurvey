 	if (use_editor && include_status) {
 		char *ai_tmp, *ci_tmp;
 		if (in_merge)
-			fprintf(fp,
+			fprintf(s->fp,
 				"#\n"
 				"# It looks like you may be committing a MERGE.\n"
 				"# If this is not correct, please remove the file\n"
