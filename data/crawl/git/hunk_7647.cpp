 		fprintf(stderr, "Unable to start PROPFIND request\n");
 	}
 
-	free(out_data);
-	free(in_buffer.buffer);
+	strbuf_release(&out_buffer.buf);
+	strbuf_release(&in_buffer);
 	curl_slist_free_all(dav_headers);
 
 	return lock_flags;
