 			return 0;
 		}
 		printf("%-15s ", refname);
-		show_tag_lines(sha1, filter->lines);
+		show_tag_lines(oid, filter->lines);
 		putchar('\n');
 	}
 
