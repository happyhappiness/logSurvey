	fprintf(fp, "To: %s\n", getAdminEmail());
	fprintf(fp, "Subject: %s\n", dead_msg());
	fclose(fp);

	sprintf(command, "mail %s < %s", getAdminEmail(), filename);

	system(command);
	unlink(filename);
    }
}
