 			continue;
 
 		if (!memcmp(header[i], "Subject", 7)) {
-			if (keep_subject)
-				sub = hdr;
-			else {
-				sub = cleanup_subject(hdr);
-				cleanup_space(sub);
+			if (!keep_subject) {
+				cleanup_subject(hdr);
+				cleanup_space(hdr);
 			}
-			output_header_lines(fout, "Subject", sub);
+			output_header_lines(fout, "Subject", hdr);
 		} else if (!memcmp(header[i], "From", 4)) {
 			handle_from(hdr);
-			fprintf(fout, "Author: %s\n", name);
-			fprintf(fout, "Email: %s\n", email);
+			fprintf(fout, "Author: %s\n", name.buf);
+			fprintf(fout, "Email: %s\n", email.buf);
 		} else {
 			cleanup_space(hdr);
-			fprintf(fout, "%s: %s\n", header[i], hdr);
+			fprintf(fout, "%s: %s\n", header[i], hdr->buf);
 		}
 	}
 	fprintf(fout, "\n");
