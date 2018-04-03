 				const char *name;
 				int pad;
 				if (opt & OUTPUT_SHOW_EMAIL)
-					name = ci.author_mail;
+					name = ci.author_mail.buf;
 				else
-					name = ci.author;
+					name = ci.author.buf;
 				pad = longest_author - utf8_strwidth(name);
 				printf(" (%s%*s %10s",
 				       name, pad, "",
 				       format_time(ci.author_time,
-						   ci.author_tz,
+						   ci.author_tz.buf,
 						   show_raw_time));
 			}
 			printf(" %*d) ",
