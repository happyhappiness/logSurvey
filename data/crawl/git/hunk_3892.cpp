 			s = literal ? "[%s]" : "[<%s>]";
 	else
 		s = literal ? " %s" : " <%s>";
-	return fprintf(outfile, s, opts->argh ? _(opts->argh) : _("..."));
+	return utf8_fprintf(outfile, s, opts->argh ? _(opts->argh) : _("..."));
 }
 
 #define USAGE_OPTS_WIDTH 24
