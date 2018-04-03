 		    printf("Error on line %d\n", linenum);
 		    exit(1);
 		}
+		/* hack to support arrays, rather than pointers */
+		if (0 == strcmp(ptr + strlen(ptr) - 2, "[]")) {
+		    curr->array_flag = 1;
+		    *(ptr + strlen(ptr) - 2) = '\0';
+		}
 		curr->type = xstrdup(ptr);
 	    } else if (!strncmp(buff, "IFDEF:", 6)) {
 		if ((ptr = strtok(buff + 6, WS)) == NULL) {
