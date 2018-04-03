 	FILE *fp = fopen_for_writing(filename);
 
 	if (!fp)
-		return error(_("cannot open %s: %s\n"), filename, strerror(errno));
+		return error_errno(_("cannot open %s"), filename);
 	fclose(fp);
 	return 0;
 }