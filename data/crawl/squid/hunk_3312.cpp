          * it's going to live as long as the process anyways */
         d = malloc(strlen(argv[j]) + 1);
         strcpy(d, argv[j]);
-        print_debug("Adding domain-controller %s\n", d);
+        debug("Adding domain-controller %s\n", d);
         if (NULL == (c = strchr(d, '\\')) && NULL == (c = strchr(d, '/'))) {
             fprintf(stderr, "Couldn't grok domain-controller %s\n", d);
             free(d);
