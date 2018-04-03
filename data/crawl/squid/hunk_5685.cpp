     char *token = NULL;
     char *tmp_line;
     int err_count = 0;
+    int is_pipe = 0;
     configFreeMemory();
     default_all();
-    if ((fp = fopen(file_name, "r")) == NULL)
+    if (file_name[0] == '!' || file_name[0] == '|') {
+	fp = popen(file_name + 1, "r");
+	is_pipe = 1;
+    } else {
+	fp = fopen(file_name, "r");
+    }
+    if (fp == NULL)
 	fatalf("Unable to open configuration file: %s: %s",
 	    file_name, xstrerror());
 #if defined(_SQUID_CYGWIN_)
     setmode(fileno(fp), O_TEXT);
 #endif
     cfg_filename = file_name;
-    if ((token = strrchr(cfg_filename, '/')))
+    if (is_pipe)
+	cfg_filename = file_name + 1;
+    else if ((token = strrchr(cfg_filename, '/')))
 	cfg_filename = token + 1;
     memset(config_input_line, '\0', BUFSIZ);
     config_lineno = 0;
     while (fgets(config_input_line, BUFSIZ, fp)) {
 	config_lineno++;
 	if ((token = strchr(config_input_line, '\n')))
 	    *token = '\0';
+	if (strncmp(config_input_line, "#line ", 6) == 0) {
+	    static char new_file_name[1024];
+	    static char *file;
+	    static char new_lineno;
+	    token = config_input_line + 6;
+	    new_lineno = strtol(token, &file, 0) - 1;
+	    if (file == token)
+		continue;	/* Not a valid #line directive, may be a comment */
+	    while (*file && isspace((unsigned char) *file))
+		file++;
+	    if (*file) {
+		if (*file != '"')
+		    continue;	/* Not a valid #line directive, may be a comment */
+		xstrncpy(new_file_name, file + 1, sizeof(new_file_name));
+		if ((token = strchr(new_file_name, '"')))
+		    *token = '\0';
+		cfg_filename = new_file_name;
+#if PROBABLY_NOT_WANTED_HERE
+		if ((token = strrchr(cfg_filename, '/')))
+		    cfg_filename = token + 1;
+#endif
+	    }
+	    config_lineno = new_lineno;
+	}
 	if (config_input_line[0] == '#')
 	    continue;
 	if (config_input_line[0] == '\0')
 	    continue;
 	debug(3, 5) ("Processing: '%s'\n", config_input_line);
 	tmp_line = xstrdup(config_input_line);
 	if (!parse_line(tmp_line)) {
-	    debug(3, 0) ("parseConfigFile: line %d unrecognized: '%s'\n",
+	    debug(3, 0) ("parseConfigFile: '%s' line %d unrecognized: '%s'\n",
+		cfg_filename,
 		config_lineno,
 		config_input_line);
 	    err_count++;
 	}
 	safe_free(tmp_line);
     }
-    fclose(fp);
+    if (is_pipe) {
+	int ret = pclose(fp);
+	if (ret != 0)
+	    fatalf("parseConfigFile: '%s' failed with exit code %d\n", file_name, ret);
+    } else {
+	fclose(fp);
+    }
     defaults_if_none();
     configDoConfigure();
     cachemgrRegister("config",