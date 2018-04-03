 	for_each_ref(one_local_ref, NULL);
 }
 
-static struct ref *set_ref_error(struct ref *refs, const char *line)
-{
-	struct ref *ref;
-
-	for (ref = refs; ref; ref = ref->next) {
-		const char *msg;
-		if (prefixcmp(line, ref->name))
-			continue;
-		msg = line + strlen(ref->name);
-		if (*msg++ != ' ')
-			continue;
-		ref->status = REF_STATUS_REMOTE_REJECT;
-		ref->error = xstrdup(msg);
-		ref->error[strlen(ref->error)-1] = '\0';
-		return ref;
-	}
-	return NULL;
-}
-
-/* a return value of -1 indicates that an error occurred,
- * but we were able to set individual ref errors. A return
- * value of -2 means we couldn't even get that far. */
 static int receive_status(int in, struct ref *refs)
 {
 	struct ref *hint;
 	char line[1000];
 	int ret = 0;
 	int len = packet_read_line(in, line, sizeof(line));
-	if (len < 10 || memcmp(line, "unpack ", 7)) {
-		fprintf(stderr, "did not receive status back\n");
-		return -2;
-	}
+	if (len < 10 || memcmp(line, "unpack ", 7))
+		return error("did not receive remote status");
 	if (memcmp(line, "unpack ok\n", 10)) {
-		fputs(line, stderr);
+		char *p = line + strlen(line) - 1;
+		if (*p == '\n')
+			*p = '\0';
+		error("unpack failed: %s", line + 7);
 		ret = -1;
 	}
 	hint = NULL;
 	while (1) {
+		char *refname;
+		char *msg;
 		len = packet_read_line(in, line, sizeof(line));
 		if (!len)
 			break;
 		if (len < 3 ||
-		    (memcmp(line, "ok", 2) && memcmp(line, "ng", 2))) {
+		    (memcmp(line, "ok ", 3) && memcmp(line, "ng ", 3))) {
 			fprintf(stderr, "protocol error: %s\n", line);
 			ret = -1;
 			break;
 		}
-		if (!memcmp(line, "ok", 2))
-			continue;
+
+		line[strlen(line)-1] = '\0';
+		refname = line + 3;
+		msg = strchr(refname, ' ');
+		if (msg)
+			*msg++ = '\0';
+
+		/* first try searching at our hint, falling back to all refs */
 		if (hint)
-			hint = set_ref_error(hint, line + 3);
+			hint = find_ref_by_name(hint, refname);
 		if (!hint)
-			hint = set_ref_error(refs, line + 3);
-		ret = -1;
+			hint = find_ref_by_name(refs, refname);
+		if (!hint) {
+			warning("remote reported status on unknown ref: %s",
+					refname);
+			continue;
+		}
+		if (hint->status != REF_STATUS_EXPECTING_REPORT) {
+			warning("remote reported status on unexpected ref: %s",
+					refname);
+			continue;
+		}
+
+		if (line[0] == 'o' && line[1] == 'k')
+			hint->status = REF_STATUS_OK;
+		else {
+			hint->status = REF_STATUS_REMOTE_REJECT;
+			ret = -1;
+		}
+		if (msg)
+			hint->remote_status = xstrdup(msg);
+		/* start our next search from the next ref */
+		hint = hint->next;
 	}
 	return ret;
 }
