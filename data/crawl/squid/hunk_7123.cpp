 	case s1:
 	    if ((strlen(buff) == 0) || (!strncmp(buff, "#", 1))) {
 		/* ignore empty and comment lines */
-
 	    } else if (!strncmp(buff, "COMMENT:", 8)) {
-		char *ptr = buff+8;
-		while(isspace(*ptr))
-			ptr++;
+		ptr = buff + 8;
+		while (isspace(*ptr))
+		    ptr++;
 		curr->comment = strdup(ptr);
 	    } else if (!strncmp(buff, "DEFAULT:", 8)) {
-		char *ptr;
-
-		if ((ptr = strtok(buff + 8, WS)) == NULL) {
-		    printf("Error on line %d\n", linenum);
-		    exit(1);
-		}
+		ptr = buff + 8;
+		while (isspace(*ptr))
+		    ptr++;
 		curr->default_value = strdup(ptr);
-
 	    } else if (!strncmp(buff, "LOC:", 4)) {
-		char *ptr;
-
 		if ((ptr = strtok(buff + 4, WS)) == NULL) {
 		    printf("Error on line %d\n", linenum);
 		    exit(1);
 		}
 		curr->loc = strdup(ptr);
-
 	    } else if (!strncmp(buff, "TYPE:", 5)) {
-		char *ptr;
-
 		if ((ptr = strtok(buff + 5, WS)) == NULL) {
 		    printf("Error on line %d\n", linenum);
 		    exit(1);
 		}
 		curr->type = strdup(ptr);
-
 	    } else if (!strcmp(buff, "DOC_START")) {
 		state = sDOC;
-
 	    } else if (!strcmp(buff, "DOC_NONE")) {
 		/* add to list of entries */
 		curr->next = entries;
 		entries = curr;
-
 		state = sSTART;
-
 	    } else {
 		printf("Error on line %d\n", linenum);
 		exit(1);
