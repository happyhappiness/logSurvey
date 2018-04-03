 	ec_process.argv = argv_ec;
 	ec_process.err = -1;
 	ec_process.stdout_to_stderr = 1;
-	if (start_command(&ec_process)) {
-		fprintf(stderr, "Failed to start emacsclient.\n");
-		return -1;
-	}
+	if (start_command(&ec_process))
+		return error("Failed to start emacsclient.");
+
 	strbuf_read(&buffer, ec_process.err, 20);
 	close(ec_process.err);
 
