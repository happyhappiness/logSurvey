 		break;
 	default:
 		if (p->score) {
-			puts(" rewrite ");
+			fputs(" rewrite ", stdout);
 			write_name_quoted(p->two->path, stdout, ' ');
 			printf("(%d%%)\n", similarity_index(p));
 		}
