 
 	if (patchbreak(line)) {
 		if (mi->message_id)
-			fprintf(mi->cmitmsg, "Message-Id: %s\n", mi->message_id);
-		fclose(mi->cmitmsg);
-		mi->cmitmsg = NULL;
+			strbuf_addf(&mi->log_message,
+				    "Message-Id: %s\n", mi->message_id);
 		return 1;
 	}
 
-	fputs(line->buf, mi->cmitmsg);
+	strbuf_addbuf(&mi->log_message, line);
 	return 0;
 }
 
