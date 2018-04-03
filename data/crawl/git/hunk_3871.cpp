 		}
 		if (bad) {
 			if (verbose) {
-				error("garbage found: %.*s/%s",
-				      len + 2, path, ent->d_name);
-				(*garbage)++;
+				struct strbuf sb = STRBUF_INIT;
+				strbuf_addf(&sb, "%.*s/%s",
+					    len + 2, path, ent->d_name);
+				report_garbage("garbage found", sb.buf);
+				strbuf_release(&sb);
 			}
 			continue;
 		}
