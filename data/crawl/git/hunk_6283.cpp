 	printf(stringed ? "' &&\n" : "'\n");
 }
 
-int show_bisect_vars(struct rev_info *revs, int reaches, int all, int flags)
+int show_bisect_vars(struct rev_list_info *info, int reaches, int all,
+		     int flags)
 {
 	int cnt;
 	char hex[41] = "", *format;
 	struct commit_list *tried;
+	struct rev_info *revs = info->revs;
 
 	if (!revs->commits && !(flags & BISECT_SHOW_TRIED))
 		return 1;
