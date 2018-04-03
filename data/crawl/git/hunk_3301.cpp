 
 	if (finish_command(&exporter))
 		die("Error while running fast-export");
-	push_update_refs_status(data, remote_refs, flags);
+	if (push_update_refs_status(data, remote_refs, flags))
+		return 1;
+
+	if (data->export_marks) {
+		strbuf_addf(&buf, "%s.tmp", data->export_marks);
+		rename(buf.buf, data->export_marks);
+		strbuf_release(&buf);
+	}
+
 	return 0;
 }
 
