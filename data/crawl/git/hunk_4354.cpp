 	uint32_t type_set = 0;
 	while ((t = buffer_read_line(&input)) && strcmp(t, "PROPS-END")) {
 		uint32_t len;
-		const char *val;
 		const char type = t[0];
 		int ch;
 
 		if (!type || t[1] != ' ')
 			die("invalid property line: %s\n", t);
 		len = atoi(&t[2]);
-		val = buffer_read_string(&input, len);
-		if (!val || strlen(val) != len)
+		strbuf_reset(&val);
+		buffer_read_binary(&input, &val, len);
+		if (val.len < len)
 			die_short_read();
 
 		/* Discard trailing newline. */
 		ch = buffer_read_char(&input);
 		if (ch == EOF)
 			die_short_read();
 		if (ch != '\n')
-			die("invalid dump: expected newline after %s", val);
+			die("invalid dump: expected newline after %s", val.buf);
 
 		switch (type) {
 		case 'K':
+			strbuf_swap(&key, &val);
+			continue;
 		case 'D':
-			strbuf_reset(&key);
-			if (val)
-				strbuf_add(&key, val, len);
-			if (type == 'K')
-				continue;
-			assert(type == 'D');
-			val = NULL;
-			len = 0;
-			/* fall through */
+			handle_property(&val, NULL, 0, &type_set);
+			continue;
 		case 'V':
-			handle_property(&key, val, len, &type_set);
+			handle_property(&key, val.buf, len, &type_set);
 			strbuf_reset(&key);
 			continue;
 		default: