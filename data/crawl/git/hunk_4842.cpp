 	strbuf_addstr(msgbuf, p);
 }
 
-static void set_author_ident_env(const char *message)
-{
-	const char *p = message;
-	if (!p)
-		die ("Could not read commit message of %s",
-				sha1_to_hex(commit->object.sha1));
-	while (*p && *p != '\n') {
-		const char *eol;
-
-		for (eol = p; *eol && *eol != '\n'; eol++)
-			; /* do nothing */
-		if (!prefixcmp(p, "author ")) {
-			char *line, *pend, *email, *timestamp;
-
-			p += 7;
-			line = xmemdupz(p, eol - p);
-			email = strchr(line, '<');
-			if (!email)
-				die ("Could not extract author email from %s",
-					sha1_to_hex(commit->object.sha1));
-			if (email == line)
-				pend = line;
-			else
-				for (pend = email; pend != line + 1 &&
-						isspace(pend[-1]); pend--);
-					; /* do nothing */
-			*pend = '\0';
-			email++;
-			timestamp = strchr(email, '>');
-			if (!timestamp)
-				die ("Could not extract author time from %s",
-					sha1_to_hex(commit->object.sha1));
-			*timestamp = '\0';
-			for (timestamp++; *timestamp && isspace(*timestamp);
-					timestamp++)
-				; /* do nothing */
-			setenv("GIT_AUTHOR_NAME", line, 1);
-			setenv("GIT_AUTHOR_EMAIL", email, 1);
-			setenv("GIT_AUTHOR_DATE", timestamp, 1);
-			free(line);
-			return;
-		}
-		p = eol;
-		if (*p == '\n')
-			p++;
-	}
-	die ("No author information found in %s",
-			sha1_to_hex(commit->object.sha1));
-}
-
 static void write_cherry_pick_head(void)
 {
 	int fd;
