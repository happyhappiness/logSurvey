 		strbuf_addf(&out, "%c %s%s%s", c, branch_get_color(color),
 			    name.buf, branch_get_color(BRANCH_COLOR_RESET));
 
-	if (item->dest)
-		strbuf_addf(&out, " -> %s", item->dest);
-	else if (verbose)
+	if (item->symref)
+		strbuf_addf(&out, " -> %s", item->symref);
+	else if (filter->verbose)
 		/* " f7c0c00 [ahead 58, behind 197] vcs-svn: drop obj_pool.h" */
-		add_verbose_info(&out, item, verbose, abbrev);
+		add_verbose_info(&out, item, filter);
 	if (column_active(colopts)) {
-		assert(!verbose && "--column and --verbose are incompatible");
+		assert(!filter->verbose && "--column and --verbose are incompatible");
 		string_list_append(&output, out.buf);
 	} else {
 		printf("%s\n", out.buf);
