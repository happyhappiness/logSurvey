 			struct strbuf buf = STRBUF_INIT;
 
 			if (strbuf_readlink(&buf, elem->path, st.st_size) < 0) {
-				error("readlink(%s): %s", elem->path,
-				      strerror(errno));
+				error_errno("readlink(%s)", elem->path);
 				return;
 			}
 			result_size = buf.len;