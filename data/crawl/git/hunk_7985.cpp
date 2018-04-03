 		break;
 	default:
 		if (p->score) {
-			char *name = quote_one(p->two->path);
-			printf(" rewrite %s (%d%%)\n", name,
-			       similarity_index(p));
-			free(name);
-			show_mode_change(p, 0);
-		} else	show_mode_change(p, 1);
+			puts(" rewrite ");
+			write_name_quoted(p->two->path, stdout, ' ');
+			printf("(%d%%)\n", similarity_index(p));
+		}
+		show_mode_change(p, !p->score);
 		break;
 	}
 }
