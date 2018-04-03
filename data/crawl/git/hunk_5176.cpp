 		paths[1] = NULL;
 	}
 
+	if (show_in_pager && (cached || list.nr))
+		die("--open-files-in-pager only works on the worktree");
+
+	if (show_in_pager && opt.pattern_list && !opt.pattern_list->next) {
+		const char *pager = path_list.items[0].string;
+		int len = strlen(pager);
+
+		if (len > 4 && is_dir_sep(pager[len - 5]))
+			pager += len - 4;
+
+		if (!strcmp("less", pager) || !strcmp("vi", pager)) {
+			struct strbuf buf = STRBUF_INIT;
+			strbuf_addf(&buf, "+/%s%s",
+					strcmp("less", pager) ? "" : "*",
+					opt.pattern_list->pattern);
+			string_list_append(buf.buf, &path_list);
+			strbuf_detach(&buf, NULL);
+		}
+	}
+
+	if (!show_in_pager)
+		setup_pager();
+
+
 	if (!use_index) {
 		if (cached)
 			die("--cached cannot be used with --no-index.");
