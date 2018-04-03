 	const char *one, *how = "bug";
 
 	one = quote_path(it->string, -1, &onebuf, s->prefix);
-	color_fprintf(s->fp, color(WT_STATUS_HEADER, s), "#\t");
+	status_printf(s, color(WT_STATUS_HEADER, s), "\t");
 	switch (d->stagemask) {
 	case 1: how = "both deleted:"; break;
 	case 2: how = "added by us:"; break;
