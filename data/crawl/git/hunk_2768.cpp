 	{ "union", "built-in union merge", ll_union_merge },
 };
 
-static void create_temp(mmfile_t *src, char *path)
+static void create_temp(mmfile_t *src, char *path, size_t len)
 {
 	int fd;
 
-	strcpy(path, ".merge_file_XXXXXX");
+	xsnprintf(path, len, ".merge_file_XXXXXX");
 	fd = xmkstemp(path);
 	if (write_in_full(fd, src->ptr, src->size) != src->size)
 		die_errno("unable to write temp-file");
