 		    exit(1);
 		}
 		curr = calloc(1, sizeof(Entry));
-		curr->name = strdup(name);
+		curr->name = xstrdup(name);
 		state = s1;
 	    } else if (!strcmp(buff, "EOF")) {
 		state = sEXIT;
 	    } else if (!strcmp(buff, "COMMENT_START")) {
 		curr = calloc(1, sizeof(Entry));
-		curr->name = strdup("comment");
-		curr->loc = strdup("none");
+		curr->name = xstrdup("comment");
+		curr->loc = xstrdup("none");
 		state = sDOC;
 	    } else {
 		printf("Error on line %d\n", linenum);
