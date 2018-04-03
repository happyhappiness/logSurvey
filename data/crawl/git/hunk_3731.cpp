 		    N_("read file names from stdin")),
 	OPT_BOOLEAN('z', NULL, &null_term_line,
 		    N_("input paths are terminated by a null character")),
+	OPT_BOOLEAN('n', "non-matching", &show_non_matching,
+		    N_("show non-matching input paths")),
 	OPT_END()
 };
 
 static void output_exclude(const char *path, struct exclude *exclude)
 {
-	char *bang  = exclude->flags & EXC_FLAG_NEGATIVE  ? "!" : "";
-	char *slash = exclude->flags & EXC_FLAG_MUSTBEDIR ? "/" : "";
+	char *bang  = (exclude && exclude->flags & EXC_FLAG_NEGATIVE)  ? "!" : "";
+	char *slash = (exclude && exclude->flags & EXC_FLAG_MUSTBEDIR) ? "/" : "";
 	if (!null_term_line) {
 		if (!verbose) {
 			write_name_quoted(path, stdout, '\n');
 		} else {
-			quote_c_style(exclude->el->src, NULL, stdout, 0);
-			printf(":%d:%s%s%s\t",
-			       exclude->srcpos,
-			       bang, exclude->pattern, slash);
+			if (exclude) {
+				quote_c_style(exclude->el->src, NULL, stdout, 0);
+				printf(":%d:%s%s%s\t",
+				       exclude->srcpos,
+				       bang, exclude->pattern, slash);
+			}
+			else {
+				printf("::\t");
+			}
 			quote_c_style(path, NULL, stdout, 0);
 			fputc('\n', stdout);
 		}
 	} else {
 		if (!verbose) {
 			printf("%s%c", path, '\0');
 		} else {
-			printf("%s%c%d%c%s%s%s%c%s%c",
-			       exclude->el->src, '\0',
-			       exclude->srcpos, '\0',
-			       bang, exclude->pattern, slash, '\0',
-			       path, '\0');
+			if (exclude)
+				printf("%s%c%d%c%s%s%s%c%s%c",
+				       exclude->el->src, '\0',
+				       exclude->srcpos, '\0',
+				       bang, exclude->pattern, slash, '\0',
+				       path, '\0');
+			else
+				printf("%c%c%c%s%c", '\0', '\0', '\0', path, '\0');
 		}
 	}
 }
