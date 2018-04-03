 		    exit(1);
 		}
 		curr->type = strdup(ptr);
+	    } else if (!strncmp(buff, "IFDEF:", 6)) {
+		if ((ptr = strtok(buff + 6, WS)) == NULL) {
+		    printf("Error on line %d\n", linenum);
+		    exit(1);
+		}
+		curr->ifdef = strdup(ptr);
 	    } else if (!strcmp(buff, "DOC_START")) {
 		state = sDOC;
 	    } else if (!strcmp(buff, "DOC_NONE")) {
