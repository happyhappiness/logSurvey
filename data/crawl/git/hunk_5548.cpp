 	unsigned in_vain = 0;
 	int got_continue = 0;
 	struct strbuf req_buf = STRBUF_INIT;
+	size_t state_len = 0;
 
+	if (args.stateless_rpc && multi_ack == 1)
+		die("--stateless-rpc requires multi_ack_detailed");
 	if (marked)
 		for_each_ref(clear_marks, NULL);
 	marked = 1;
