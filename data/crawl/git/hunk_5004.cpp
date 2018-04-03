 		}
 
 		printf("%.*s", length, hex);
-		if (opt & OUTPUT_ANNOTATE_COMPAT)
-			printf("\t(%10s\t%10s\t%d)", ci.author,
+		if (opt & OUTPUT_ANNOTATE_COMPAT) {
+			const char *name;
+			if (opt & OUTPUT_SHOW_EMAIL)
+				name = ci.author_mail;
+			else
+				name = ci.author;
+			printf("\t(%10s\t%10s\t%d)", name,
 			       format_time(ci.author_time, ci.author_tz,
 					   show_raw_time),
 			       ent->lno + 1 + cnt);
-		else {
+		} else {
 			if (opt & OUTPUT_SHOW_SCORE)
 				printf(" %*d %02d",
 				       max_score_digits, ent->score,
