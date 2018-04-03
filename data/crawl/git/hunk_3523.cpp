 		return get_colorbool_found ? 0 : 1;
 }
 
+static void check_blob_write(void)
+{
+	if (given_config_blob)
+		die("writing config blobs is not supported");
+}
+
 int cmd_config(int argc, const char **argv, const char *prefix)
 {
 	int nongit = !startup_info->have_repository;
