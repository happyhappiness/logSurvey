 		if (!askpass)
 			askpass = getenv("SSH_ASKPASS");
 		if (askpass && *askpass)
-			return do_askpass(askpass, prompt);
+			r = do_askpass(askpass, prompt);
 	}
 
-	r = git_terminal_prompt(prompt, flags & PROMPT_ECHO);
 	if (!r)
-		die_errno("could not read '%s'", prompt);
+		r = git_terminal_prompt(prompt, flags & PROMPT_ECHO);
+	if (!r) {
+		/* prompts already contain ": " at the end */
+		die("could not read %s%s", prompt, strerror(errno));
+	}
 	return r;
 }
 