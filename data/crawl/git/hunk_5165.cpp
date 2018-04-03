 	info->message_id = strbuf_detach(&buf, NULL);
 }
 
+static void print_signature(void)
+{
+	if (signature && *signature)
+		printf("-- \n%s\n\n", signature);
+}
+
 static void make_cover_letter(struct rev_info *rev, int use_stdout,
 			      int numbered, int numbered_files,
 			      struct commit *origin,
