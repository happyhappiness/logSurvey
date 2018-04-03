    fp = fopen(filename, "w");
    if (fp != NULL) {
	fprintf(fp, "From: %s\n", appname);
	fprintf(fp, "To: %s\n", Config.adminEmail);
	fprintf(fp, "Subject: %s\n", dead_msg());
	fclose(fp);
	sprintf(command, "mail %s < %s", Config.adminEmail, filename);
	system(command);	/* XXX should avoid system(3) */
	unlink(filename);
    }
}

void print_warranty()
{
    if (Config.adminEmail)
	mail_warranty();
    else
	puts(dead_msg());
