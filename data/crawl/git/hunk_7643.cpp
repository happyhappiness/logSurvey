 {
 	unsigned char sha1[20];
 	char *url;
-	struct buffer buffer;
+	struct strbuf buffer = STRBUF_INIT;
 	char *data;
 	int i = 0;
 
 	struct active_request_slot *slot;
 	struct slot_results results;
 
-	data = xcalloc(1, 4096);
-	buffer.size = 4096;
-	buffer.posn = 0;
-	buffer.buffer = data;
-
 	if (push_verbosely)
 		fprintf(stderr, "Getting pack list\n");
 
