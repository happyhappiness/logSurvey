		die("cannot run browser");

	printf("Launching default browser to display HTML ...\n");
	ShellExecute(NULL, "open", htmlpath, NULL, "\\", 0);

	FreeLibrary(shell32);
}

int link(const char *oldpath, const char *newpath)