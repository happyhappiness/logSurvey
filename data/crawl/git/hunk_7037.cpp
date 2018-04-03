 	}
 
 	if (count > limit)
-		printf("\n* %s: (%d commits)\n", name, count);
+		strbuf_addf(out, "\n* %s: (%d commits)\n", name, count);
 	else
-		printf("\n* %s:\n", name);
+		strbuf_addf(out, "\n* %s:\n", name);
 
 	for (i = 0; i < subjects.nr; i++)
 		if (i >= limit)
-			printf("  ...\n");
+			strbuf_addf(out, "  ...\n");
 		else
-			printf("  %s\n", subjects.list[i]);
+			strbuf_addf(out, "  %s\n", subjects.list[i]);
 
 	clear_commit_marks((struct commit *)branch, flags);
 	clear_commit_marks(head, flags);
