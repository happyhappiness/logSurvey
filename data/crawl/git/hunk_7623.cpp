 	const char *set = diff_get_color_opt(o, DIFF_METAINFO);
 	const char *reset = diff_get_color_opt(o, DIFF_RESET);
 
-	a_one = quote_two("a/", name_a + (*name_a == '/'));
-	b_two = quote_two("b/", name_b + (*name_b == '/'));
+	a_one = quote_two(o->a_prefix, name_a + (*name_a == '/'));
+	b_two = quote_two(o->b_prefix, name_b + (*name_b == '/'));
 	lbl[0] = DIFF_FILE_VALID(one) ? a_one : "/dev/null";
 	lbl[1] = DIFF_FILE_VALID(two) ? b_two : "/dev/null";
 	printf("%sdiff --git %s %s%s\n", set, a_one, b_two, reset);
