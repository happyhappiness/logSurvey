 			break;
 	}
 
-	fprintf(stderr, "Failed to run command '%s': %s\n",
+	fprintf(stderr, _("failed to run command '%s': %s\n"),
 		cmd, strerror(errno));
 
 	return 1;
