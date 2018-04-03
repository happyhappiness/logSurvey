 void usage_with_options(const char * const *usagestr,
                         const struct option *opts)
 {
-	struct strbuf sb;
-
-	strbuf_init(&sb, 4096);
-	strbuf_addstr(&sb, *usagestr);
-	strbuf_addch(&sb, '\n');
-	while (*++usagestr)
-		strbuf_addf(&sb, "    %s\n", *usagestr);
+	fprintf(stderr, "usage: %s\n", *usagestr++);
+	while (*usagestr && **usagestr)
+		fprintf(stderr, "   or: %s\n", *usagestr++);
+	while (*usagestr)
+		fprintf(stderr, "    %s\n", *usagestr++);
 
 	if (opts->type != OPTION_GROUP)
-		strbuf_addch(&sb, '\n');
+		fputc('\n', stderr);
 
 	for (; opts->type != OPTION_END; opts++) {
 		size_t pos;
 		int pad;
 
 		if (opts->type == OPTION_GROUP) {
-			strbuf_addch(&sb, '\n');
+			fputc('\n', stderr);
 			if (*opts->help)
-				strbuf_addf(&sb, "%s\n", opts->help);
+				fprintf(stderr, "%s\n", opts->help);
 			continue;
 		}
 
-		pos = sb.len;
-		strbuf_addstr(&sb, "    ");
+		pos = fprintf(stderr, "    ");
 		if (opts->short_name)
-			strbuf_addf(&sb, "-%c", opts->short_name);
+			pos += fprintf(stderr, "-%c", opts->short_name);
 		if (opts->long_name && opts->short_name)
-			strbuf_addstr(&sb, ", ");
+			pos += fprintf(stderr, ", ");
 		if (opts->long_name)
-			strbuf_addf(&sb, "--%s", opts->long_name);
+			pos += fprintf(stderr, "--%s", opts->long_name);
 
 		switch (opts->type) {
 		case OPTION_INTEGER:
-			strbuf_addstr(&sb, " <n>");
+			pos += fprintf(stderr, " <n>");
 			break;
 		case OPTION_STRING:
 			if (opts->argh)
-				strbuf_addf(&sb, " <%s>", opts->argh);
+				pos += fprintf(stderr, " <%s>", opts->argh);
 			else
-				strbuf_addstr(&sb, " ...");
+				pos += fprintf(stderr, " ...");
 			break;
 		default:
 			break;
 		}
 
-		pad = sb.len - pos;
-		if (pad <= USAGE_OPTS_WIDTH)
-			pad = USAGE_OPTS_WIDTH - pad;
+		if (pos <= USAGE_OPTS_WIDTH)
+			pad = USAGE_OPTS_WIDTH - pos;
 		else {
-			strbuf_addch(&sb, '\n');
+			fputc('\n', stderr);
 			pad = USAGE_OPTS_WIDTH;
 		}
-		strbuf_addf(&sb, "%*s%s\n", pad + USAGE_GAP, "", opts->help);
+		fprintf(stderr, "%*s%s\n", pad + USAGE_GAP, "", opts->help);
 	}
-	usage(sb.buf);
+	fputc('\n', stderr);
+
+	exit(129);
 }