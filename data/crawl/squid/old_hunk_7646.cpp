    if ((fp = fopen(filename, "w")) == NULL)
	return;
    fprintf(fp, "From: %s\n", appname);
    fprintf(fp, "To: %s\n", getAdminEmail());
    fprintf(fp, "Subject: %s\n", dead_msg());
    fclose(fp);
    sprintf(command, "mail %s < %s", getAdminEmail(), filename);
    system(command);		/* XXX should avoid system(3) */
    unlink(filename);
}
