 	return i;
 }
 
-static void show_list(const char *title, struct string_list *list)
+static void show_list(const char *title, struct string_list *list,
+		      const char *extra_arg)
 {
 	int i;
 
 	if (!list->nr)
 		return;
 
-	printf(title, list->nr > 1 ? "es" : "");
+	printf(title, list->nr > 1 ? "es" : "", extra_arg);
 	printf("\n    ");
 	for (i = 0; i < list->nr; i++)
 		printf("%s%s", i ? " " : "", list->items[i].string);
