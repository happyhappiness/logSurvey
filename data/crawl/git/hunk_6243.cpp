 		printf("Message-Id: <%s>\n", opt->message_id);
 		graph_show_oneline(opt->graph);
 	}
-	if (opt->ref_message_id) {
-		printf("In-Reply-To: <%s>\nReferences: <%s>\n",
-		       opt->ref_message_id, opt->ref_message_id);
+	if (opt->ref_message_ids && opt->ref_message_ids->nr > 0) {
+		int i, n;
+		n = opt->ref_message_ids->nr;
+		printf("In-Reply-To: <%s>\n", opt->ref_message_ids->items[n-1].string);
+		for (i = 0; i < n; i++)
+			printf("%s<%s>\n", (i > 0 ? "\t" : "References: "),
+			       opt->ref_message_ids->items[i].string);
 		graph_show_oneline(opt->graph);
 	}
 	if (opt->mime_boundary) {
 		static char subject_buffer[1024];
 		static char buffer[1024];
+		struct strbuf filename =  STRBUF_INIT;
 		*need_8bit_cte_p = -1; /* NEVER */
 		snprintf(subject_buffer, sizeof(subject_buffer) - 1,
 			 "%s"
