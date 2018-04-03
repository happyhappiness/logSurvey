 		}
 	}
 
-	if (apply_fragments(&buf, patch) < 0)
+	img = strbuf_detach(&buf, &len);
+	prepare_image(&image, img, len, !patch->is_binary);
+
+	if (apply_fragments(&image, patch) < 0)
 		return -1; /* note with --reject this succeeds. */
-	patch->result = strbuf_detach(&buf, &patch->resultsize);
+	patch->result = image.buf;
+	patch->resultsize = image.len;
+	free(image.line_allocated);
 
 	if (0 < patch->is_delete && patch->resultsize)
 		return error("removal patch leaves file contents");