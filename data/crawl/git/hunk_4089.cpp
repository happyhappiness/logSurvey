 #include "cache.h"
 #include "string-list.h"
 
+/*
+ * Parse an argument into a string list.  arg should either be a
+ * ':'-separated list of strings, or "-" to indicate an empty string
+ * list (as opposed to "", which indicates a string list containing a
+ * single empty string).  list->strdup_strings must be set.
+ */
+void parse_string_list(struct string_list *list, const char *arg)
+{
+	if (!strcmp(arg, "-"))
+		return;
+
+	(void)string_list_split(list, arg, ':', -1);
+}
+
 void write_list(const struct string_list *list)
 {
 	int i;
 	for (i = 0; i < list->nr; i++)
 		printf("[%d]: \"%s\"\n", i, list->items[i].string);
 }
 
+void write_list_compact(const struct string_list *list)
+{
+	int i;
+	if (!list->nr)
+		printf("-\n");
+	else {
+		printf("%s", list->items[0].string);
+		for (i = 1; i < list->nr; i++)
+			printf(":%s", list->items[i].string);
+		printf("\n");
+	}
+}
+
+int prefix_cb(struct string_list_item *item, void *cb_data)
+{
+	const char *prefix = (const char *)cb_data;
+	return !prefixcmp(item->string, prefix);
+}
+
 int main(int argc, char **argv)
 {
 	if (argc == 5 && !strcmp(argv[1], "split")) {
