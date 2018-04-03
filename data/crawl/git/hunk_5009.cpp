 		askpass = askpass_program;
 	if (!askpass)
 		askpass = getenv("SSH_ASKPASS");
-	if (!askpass || !(*askpass))
-		return getpass(prompt);
+	if (!askpass || !(*askpass)) {
+		char *result = getpass(prompt);
+		if (!result)
+			die_errno("Could not read password");
+		return result;
+	}
 
 	args[0] = askpass;
 	args[1]	= prompt;