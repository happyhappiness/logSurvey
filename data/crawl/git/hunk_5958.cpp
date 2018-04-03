 	finish_command(&ec_process);
 
 	if (prefixcmp(buffer.buf, "emacsclient")) {
-		fprintf(stderr, "Failed to parse emacsclient version.\n");
 		strbuf_release(&buffer);
-		return -1;
+		return error("Failed to parse emacsclient version.");
 	}
 
 	strbuf_remove(&buffer, 0, strlen("emacsclient"));
 	version = atoi(buffer.buf);
 
 	if (version < 22) {
-		fprintf(stderr,
-			"emacsclient version '%d' too old (< 22).\n",
-			version);
 		strbuf_release(&buffer);
-		return -1;
+		return error("emacsclient version '%d' too old (< 22).",
+			version);
 	}
 
 	strbuf_release(&buffer);