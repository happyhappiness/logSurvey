 	if (alias_string) {
 		if (alias_string[0] == '!') {
 			if (*argcp > 1) {
-				int i, sz = PATH_MAX;
-				char *s = xmalloc(sz), *new_alias = s;
+				struct strbuf buf;
 
-				add_to_string(&s, &sz, alias_string, 0);
+				strbuf_init(&buf, PATH_MAX);
+				strbuf_addstr(&buf, alias_string);
+				sq_quote_argv(&buf, (*argv) + 1, *argcp - 1, PATH_MAX);
 				free(alias_string);
-				alias_string = new_alias;
-				for (i = 1; i < *argcp &&
-					!add_to_string(&s, &sz, " ", 0) &&
-					!add_to_string(&s, &sz, (*argv)[i], 1)
-					; i++)
-					; /* do nothing */
-				if (!sz)
-					die("Too many or long arguments");
+				alias_string = buf.buf;
 			}
 			trace_printf("trace: alias to shell cmd: %s => %s\n",
 				     alias_command, alias_string + 1);
