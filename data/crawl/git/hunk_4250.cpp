 
 	return buffer.buf;
 }
+
+char *git_prompt(const char *prompt, int flags)
+{
+	char *r;
+
+	if (flags & PROMPT_ASKPASS) {
+		const char *askpass;
+
+		askpass = getenv("GIT_ASKPASS");
+		if (!askpass)
+			askpass = askpass_program;
+		if (!askpass)
+			askpass = getenv("SSH_ASKPASS");
+		if (askpass && *askpass)
+			return do_askpass(askpass, prompt);
+	}
+
+	r = getpass(prompt);
+	if (!r)
+		die_errno("could not read '%s'", prompt);
+	return r;
+}
+
+char *git_getpass(const char *prompt)
+{
+	return git_prompt(prompt, PROMPT_ASKPASS);
+}
