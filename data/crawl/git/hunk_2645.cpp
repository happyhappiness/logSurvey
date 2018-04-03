 				cleanup_subject(mi, hdr);
 				cleanup_space(hdr);
 			}
-			output_header_lines(fout, "Subject", hdr);
+			output_header_lines(mi->output, "Subject", hdr);
 		} else if (!strcmp(header[i], "From")) {
 			cleanup_space(hdr);
 			handle_from(mi, hdr);
-			fprintf(fout, "Author: %s\n", mi->name.buf);
-			fprintf(fout, "Email: %s\n", mi->email.buf);
+			fprintf(mi->output, "Author: %s\n", mi->name.buf);
+			fprintf(mi->output, "Email: %s\n", mi->email.buf);
 		} else {
 			cleanup_space(hdr);
-			fprintf(fout, "%s: %s\n", header[i], hdr->buf);
+			fprintf(mi->output, "%s: %s\n", header[i], hdr->buf);
 		}
 	}
-	fprintf(fout, "\n");
+	fprintf(mi->output, "\n");
 }
 
-static int mailinfo(struct mailinfo *mi,
-		    FILE *in, FILE *out, const char *msg, const char *patch)
+static int mailinfo(struct mailinfo *mi, const char *msg, const char *patch)
 {
 	int peek;
 	struct strbuf line = STRBUF_INIT;
 
-	fin = in;
-	fout = out;
-
 	cmitmsg = fopen(msg, "w");
 	if (!cmitmsg) {
 		perror(msg);
