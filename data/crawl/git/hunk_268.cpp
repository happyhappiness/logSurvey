 
 	if (fprintf(out, "%s", PACKED_REFS_HEADER) < 0) {
 		strbuf_addf(err, "error writing to %s: %s",
-			    get_tempfile_path(&refs->tempfile), strerror(errno));
+			    get_tempfile_path(refs->tempfile), strerror(errno));
 		goto error;
 	}
 
