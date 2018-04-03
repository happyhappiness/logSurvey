 	for (i = 0; i < l->nr; i++) {
 		struct string_list_item *it;
 		it = &(l->items[i]);
-		color_fprintf(s->fp, color(WT_STATUS_HEADER, s), "#\t");
-		color_fprintf_ln(s->fp, color(WT_STATUS_UNTRACKED, s), "%s",
-				 quote_path(it->string, strlen(it->string),
+		status_printf(s, color(WT_STATUS_HEADER, s), "\t");
+		status_printf_more(s, color(WT_STATUS_UNTRACKED, s),
+			"%s\n", quote_path(it->string, strlen(it->string),
 					    &buf, s->prefix));
 	}
 	strbuf_release(&buf);
