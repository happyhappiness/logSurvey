 	return get_pathspec(prefix, result);
 }
 
-static void show_list(const char *label, struct path_list *list)
+static void show_list(const char *label, struct string_list *list)
 {
 	if (list->nr > 0) {
 		int i;
 		printf("%s", label);
 		for (i = 0; i < list->nr; i++)
-			printf("%s%s", i > 0 ? ", " : "", list->items[i].path);
+			printf("%s%s", i > 0 ? ", " : "",
+					list->items[i].string);
 		putchar('\n');
 	}
 }
