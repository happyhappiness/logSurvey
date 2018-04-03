 			rm->merge ? "" : "not-for-merge",
 			note);
 
-		if (ref)
-			update_local_ref(ref, note, verbose);
+		if (ref) {
+			update_local_ref(ref, what, verbose, note);
+			if (*note) {
+				if (!shown_url) {
+					fprintf(stderr, "From %.*s\n",
+							url_len, url);
+					shown_url = 1;
+				}
+				fprintf(stderr, " %s\n", note);
+			}
+		}
 	}
 	fclose(fp);
 }
