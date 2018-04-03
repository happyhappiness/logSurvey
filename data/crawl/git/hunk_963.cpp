 
 		strbuf_expand(&expanded_path, interpolated_path,
 			      expand_path, &context);
-		strlcpy(interp_path, expanded_path.buf, PATH_MAX);
+
+		rlen = strlcpy(interp_path, expanded_path.buf,
+			       sizeof(interp_path));
+		if (rlen >= sizeof(interp_path)) {
+			logerror("interpolated path too large: %s",
+				 interp_path);
+			return NULL;
+		}
+
 		strbuf_release(&expanded_path);
 		loginfo("Interpolated dir '%s'", interp_path);
 
