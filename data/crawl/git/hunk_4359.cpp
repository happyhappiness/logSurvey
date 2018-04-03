 		uint32_t len;
 		const char *val;
 		const char type = t[0];
+		int ch;
 
 		if (!type || t[1] != ' ')
 			die("invalid property line: %s\n", t);
 		len = atoi(&t[2]);
 		val = buffer_read_string(&input, len);
-		buffer_skip_bytes(&input, 1);	/* Discard trailing newline. */
+		if (!val || strlen(val) != len)
+			die_short_read();
+
+		/* Discard trailing newline. */
+		ch = buffer_read_char(&input);
+		if (ch == EOF)
+			die_short_read();
+		if (ch != '\n')
+			die("invalid dump: expected newline after %s", val);
 
 		switch (type) {
 		case 'K':
