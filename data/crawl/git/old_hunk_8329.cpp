	if (!dir)
		return;

	while ((de = readdir(dir)) != NULL) {
		char name[100];
		unsigned char sha1[20];
