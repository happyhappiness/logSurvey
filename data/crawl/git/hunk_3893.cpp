 		if (opts->long_name)
 			pos += fprintf(outfile, "--%s", opts->long_name);
 		if (opts->type == OPTION_NUMBER)
-			pos += fprintf(outfile, "-NUM");
+			pos += utf8_fprintf(outfile, _("-NUM"));
 
 		if ((opts->flags & PARSE_OPT_LITERAL_ARGHELP) ||
 		    !(opts->flags & PARSE_OPT_NOARG))
