 	char *cursor;
 
 	if (arg[1])
-	  argp_error (state, _("Malformed density argument: '%s'"), arg);
+	  argp_error (state, _("Malformed density argument: %s"), quote (arg));
 	
 	strcpy (buf, DEVICE_PREFIX);
 	cursor = buf + strlen (buf);
