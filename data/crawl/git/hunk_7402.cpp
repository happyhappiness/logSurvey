 		return -1;
 }
 
-static struct path_list mailmap = {NULL, 0, 0, 0};
-
-static void insert_one_record(struct path_list *list,
+static void insert_one_record(struct shortlog *log,
 			      const char *author,
 			      const char *oneline)
 {
-	const char *dot3 = common_repo_prefix;
+	const char *dot3 = log->common_repo_prefix;
 	char *buffer, *p;
 	struct path_list_item *item;
 	struct path_list *onelines;
