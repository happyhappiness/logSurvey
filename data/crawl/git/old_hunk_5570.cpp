		use_message = edit_message;
	if (amend && !use_message)
		use_message = "HEAD";
	if (use_message) {
		unsigned char sha1[20];
		static char utf8[] = "UTF-8";
