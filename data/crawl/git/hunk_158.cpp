 static int check_ref_format_branch(const char *arg)
 {
 	struct strbuf sb = STRBUF_INIT;
+	const char *name;
 	int nongit;
 
 	setup_git_directory_gently(&nongit);
-	if (strbuf_check_branch_ref(&sb, arg))
+	if (strbuf_check_branch_ref(&sb, arg) ||
+	    !skip_prefix(sb.buf, "refs/heads/", &name))
 		die("'%s' is not a valid branch name", arg);
-	printf("%s\n", sb.buf + 11);
+	printf("%s\n", name);
 	return 0;
 }
 