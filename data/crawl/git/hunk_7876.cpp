 
 		switch (opts->type) {
 		case OPTION_INTEGER:
-			pos += fprintf(stderr, " <n>");
+			if (opts->flags & PARSE_OPT_OPTARG)
+				pos += fprintf(stderr, " [<n>]");
+			else
+				pos += fprintf(stderr, " <n>");
 			break;
 		case OPTION_STRING:
-			if (opts->argh)
-				pos += fprintf(stderr, " <%s>", opts->argh);
-			else
-				pos += fprintf(stderr, " ...");
+		case OPTION_CALLBACK:
+			if (opts->argh) {
+				if (opts->flags & PARSE_OPT_OPTARG)
+					pos += fprintf(stderr, " [<%s>]", opts->argh);
+				else
+					pos += fprintf(stderr, " <%s>", opts->argh);
+			} else {
+				if (opts->flags & PARSE_OPT_OPTARG)
+					pos += fprintf(stderr, " [...]");
+				else
+					pos += fprintf(stderr, " ...");
+			}
 			break;
 		default:
 			break;
