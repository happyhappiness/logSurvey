 			continue;
 
 		pos = fprintf(stderr, "    ");
-		if (opts->short_name) {
+		if (opts->short_name && !(opts->flags & PARSE_OPT_NEGHELP)) {
 			if (opts->flags & PARSE_OPT_NODASH)
 				pos += fprintf(stderr, "%c", opts->short_name);
 			else
