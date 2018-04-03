 		save_user_format(rev, strchr(arg, ':') + 1, arg[0] == 't');
 		return;
 	}
-	for (i = 0; i < ARRAY_SIZE(cmt_fmts); i++) {
-		if (!strncmp(arg, cmt_fmts[i].n, cmt_fmts[i].cmp_len) &&
-		    !strncmp(arg, cmt_fmts[i].n, strlen(arg))) {
-			if (cmt_fmts[i].v == CMIT_FMT_ONELINE)
-				rev->use_terminator = 1;
-			rev->commit_format = cmt_fmts[i].v;
-			return;
-		}
-	}
+
 	if (strchr(arg, '%')) {
 		save_user_format(rev, arg, 1);
 		return;
 	}
 
-	die("invalid --pretty format: %s", arg);
+	commit_format = find_commit_format(arg);
+	if (!commit_format)
+		die("invalid --pretty format: %s", arg);
+
+	rev->commit_format = commit_format->format;
+	rev->use_terminator = commit_format->is_tformat;
 }
 
 /*