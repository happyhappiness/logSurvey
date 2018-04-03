 					strbuf_addf(&note, "%s ", kind);
 				strbuf_addf(&note, "'%s' of ", what);
 			}
-			fprintf(fp, "%s\t%s\t%s",
-				sha1_to_hex(rm->old_sha1),
-				rm->merge ? "" : "not-for-merge",
-				note.buf);
-			for (i = 0; i < url_len; ++i)
-				if ('\n' == url[i])
-					fputs("\\n", fp);
-				else
-					fputc(url[i], fp);
-			fputc('\n', fp);
+			switch (rm->fetch_head_status) {
+			case FETCH_HEAD_NOT_FOR_MERGE:
+				merge_status_marker = "not-for-merge";
+				/* fall-through */
+			case FETCH_HEAD_MERGE:
+				fprintf(fp, "%s\t%s\t%s",
+					sha1_to_hex(rm->old_sha1),
+					merge_status_marker,
+					note.buf);
+				for (i = 0; i < url_len; ++i)
+					if ('\n' == url[i])
+						fputs("\\n", fp);
+					else
+						fputc(url[i], fp);
+				fputc('\n', fp);
+				break;
+			default:
+				/* do not write anything to FETCH_HEAD */
+				break;
+			}
 
 			strbuf_reset(&note);
 			if (ref) {
