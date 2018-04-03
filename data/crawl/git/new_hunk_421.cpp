	marksfile = fopen(marksfilename, "r");
	if (!marksfile) {
		regenerate_marks();
		marksfile = xfopen(marksfilename, "r");
		fclose(marksfile);
	} else {
		strbuf_addf(&sb, ":%d ", latestrev);