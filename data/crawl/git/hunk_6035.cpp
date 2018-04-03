 						    kind);
 			note_len += sprintf(note + note_len, "'%s' of ", what);
 		}
-		note_len += sprintf(note + note_len, "%.*s", url_len, url);
-		fprintf(fp, "%s\t%s\t%s\n",
+		note[note_len] = '\0';
+		fprintf(fp, "%s\t%s\t%s",
 			sha1_to_hex(commit ? commit->object.sha1 :
 				    rm->old_sha1),
 			rm->merge ? "" : "not-for-merge",
 			note);
+		for (i = 0; i < url_len; ++i)
+			if ('\n' == url[i])
+				fputs("\\n", fp);
+			else
+				fputc(url[i], fp);
+		fputc('\n', fp);
 
 		if (ref)
 			rc |= update_local_ref(ref, what, note);