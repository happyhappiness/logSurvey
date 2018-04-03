 	struct strbuf out = STRBUF_INIT;
 	struct commit_list *j;
 	int fd;
+	struct pretty_print_context ctx = {0};
 
 	printf("Squash commit -- not updating HEAD\n");
 	fd = open(git_path("SQUASH_MSG"), O_WRONLY | O_CREAT, 0666);
