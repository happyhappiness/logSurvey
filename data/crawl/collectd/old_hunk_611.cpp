	}

	return;
}
#endif /* HAVE_LIBKSTAT */

void exit_usage (char *name)
{
	printf ("Usage: %s [OPTIONS]\n\n"
			
			"Available options:\n"
			"  General:\n"
			/*
			"    -C <dir>        Configuration file.\n"
			"                    Default: %s\n"
			*/
			"    -P <file>       PID File.\n"
			"                    Default: %s\n"
			"    -M <dir>        Module/Plugin directory.\n"
			"                    Default: %s\n"
			"    -D <dir>        Data storage directory.\n"
			"                    Default: %s\n"
			"    -f              Don't fork to the background.\n"
#ifdef HAVE_LIBRRD
			"    -l              Start in local mode (no network).\n"
			"    -c              Start in client (sender) mode.\n"
			"    -s              Start in server (listener) mode.\n"
