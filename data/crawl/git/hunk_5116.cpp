 			fprintf(stderr, " %.*s", 8,
 				sha1_to_hex(pp->item->object.sha1));
 
-		sp = strstr(buf, "\n\n");
-		if (sp) {
-			sp += 2;
-			for (ep = sp; *ep && *ep != '\n'; ep++)
-				;
-			fprintf(stderr, " %.*s", (int)(ep - sp), sp);
-		}
+		subject_len = find_commit_subject(buf, &subject_start);
+		if (subject_len)
+			fprintf(stderr, " %.*s", subject_len, subject_start);
 		fprintf(stderr, "\n");
 	}
 }