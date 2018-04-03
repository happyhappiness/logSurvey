 			*header.typeflag = TYPEFLAG_REG;
 			mode = (mode | ((mode & 0100) ? 0777 : 0666)) & ~tar_umask;
 		} else {
-			error("unsupported file mode: 0%o (SHA1: %s)",
-			      mode, sha1_to_hex(sha1));
-			return;
+			return error("unsupported file mode: 0%o (SHA1: %s)",
+					mode, sha1_to_hex(sha1));
 		}
-		if (path->len > sizeof(header.name)) {
-			int plen = get_path_prefix(path, sizeof(header.prefix));
-			int rest = path->len - plen - 1;
+		if (pathlen > sizeof(header.name)) {
+			size_t plen = get_path_prefix(path, pathlen,
+					sizeof(header.prefix));
+			size_t rest = pathlen - plen - 1;
 			if (plen > 0 && rest <= sizeof(header.name)) {
-				memcpy(header.prefix, path->buf, plen);
-				memcpy(header.name, path->buf + plen + 1, rest);
+				memcpy(header.prefix, path, plen);
+				memcpy(header.name, path + plen + 1, rest);
 			} else {
 				sprintf(header.name, "%s.data",
 				        sha1_to_hex(sha1));
 				strbuf_append_ext_header(&ext_header, "path",
-				                         path->buf, path->len);
+						path, pathlen);
 			}
 		} else
-			memcpy(header.name, path->buf, path->len);
+			memcpy(header.name, path, pathlen);
 	}
 
 	if (S_ISLNK(mode) && buffer) {
