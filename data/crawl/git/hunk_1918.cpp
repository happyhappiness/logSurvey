 		packet_buf_write(&req_buf, "done\n");
 		send_request(args, fd[1], &req_buf);
 	}
-	if (args->verbose)
-		fprintf(stderr, "done\n");
+	print_verbose(args, "done");
 	if (retval != 0) {
 		multi_ack = 0;
 		flushes++;
