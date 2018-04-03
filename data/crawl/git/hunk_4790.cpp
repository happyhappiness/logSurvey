 	one = quote_path(one_name, -1, &onebuf, s->prefix);
 	two = quote_path(two_name, -1, &twobuf, s->prefix);
 
-	color_fprintf(s->fp, color(WT_STATUS_HEADER, s), "#\t");
+	status_printf(s, color(WT_STATUS_HEADER, s), "\t");
 	switch (status) {
 	case DIFF_STATUS_ADDED:
-		color_fprintf(s->fp, c, "new file:   %s", one);
+		status_printf_more(s, c, "new file:   %s", one);
 		break;
 	case DIFF_STATUS_COPIED:
-		color_fprintf(s->fp, c, "copied:     %s -> %s", one, two);
+		status_printf_more(s, c, "copied:     %s -> %s", one, two);
 		break;
 	case DIFF_STATUS_DELETED:
-		color_fprintf(s->fp, c, "deleted:    %s", one);
+		status_printf_more(s, c, "deleted:    %s", one);
 		break;
 	case DIFF_STATUS_MODIFIED:
-		color_fprintf(s->fp, c, "modified:   %s", one);
+		status_printf_more(s, c, "modified:   %s", one);
 		break;
 	case DIFF_STATUS_RENAMED:
-		color_fprintf(s->fp, c, "renamed:    %s -> %s", one, two);
+		status_printf_more(s, c, "renamed:    %s -> %s", one, two);
 		break;
 	case DIFF_STATUS_TYPE_CHANGED:
-		color_fprintf(s->fp, c, "typechange: %s", one);
+		status_printf_more(s, c, "typechange: %s", one);
 		break;
 	case DIFF_STATUS_UNKNOWN:
-		color_fprintf(s->fp, c, "unknown:    %s", one);
+		status_printf_more(s, c, "unknown:    %s", one);
 		break;
 	case DIFF_STATUS_UNMERGED:
-		color_fprintf(s->fp, c, "unmerged:   %s", one);
+		status_printf_more(s, c, "unmerged:   %s", one);
 		break;
 	default:
 		die("bug: unhandled diff status %c", status);
 	}
 	if (extra.len) {
-		color_fprintf(s->fp, color(WT_STATUS_HEADER, s), "%s", extra.buf);
+		status_printf_more(s, color(WT_STATUS_HEADER, s), "%s", extra.buf);
 		strbuf_release(&extra);
 	}
-	fprintf(s->fp, "\n");
+	status_printf_more(s, GIT_COLOR_NORMAL, "\n");
 	strbuf_release(&onebuf);
 	strbuf_release(&twobuf);
 }
