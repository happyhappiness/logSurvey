 	struct strbuf buf = STRBUF_INIT;
 
 	if (sha1_object_info_extended(data->sha1, &data->info, LOOKUP_REPLACE_OBJECT) < 0) {
-		printf("%s missing\n", obj_name);
+		printf("%s missing\n", obj_name ? obj_name : sha1_to_hex(data->sha1));
 		fflush(stdout);
 		return;
 	}
