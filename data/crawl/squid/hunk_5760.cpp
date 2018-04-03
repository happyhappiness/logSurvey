 	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
 	exit(1);
     }
-
     while (fgets(buf, 256, stdin) != NULL) {
 	user = strtok(buf, " \r\n");
 	passwd = strtok(NULL, "\r\n");
