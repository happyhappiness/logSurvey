 		die_errno("Full write to remote helper failed");
 }
 
-static int recvline_fh(FILE *helper, struct strbuf *buffer)
+static int recvline_fh(FILE *helper, struct strbuf *buffer, const char *name)
 {
 	strbuf_reset(buffer);
 	if (debug)
 		fprintf(stderr, "Debug: Remote helper: Waiting...\n");
 	if (strbuf_getline(buffer, helper, '\n') == EOF) {
 		if (debug)
 			fprintf(stderr, "Debug: Remote helper quit.\n");
-		die("Reading from remote helper failed");
+		die("Reading from helper 'git-remote-%s' failed", name);
 	}
 
 	if (debug)
