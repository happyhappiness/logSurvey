static void
usage(void)
{
    fprintf(stderr,
	"Usage: %s [-hsvzCDFRUVY] [-f config-file] [-[au] port] [-k signal]\n"
	"       -a port   Specify ASCII port number (default: %d).\n"
	"       -f file   Use given config-file instead of\n"
	"                 %s\n"
	"       -h        Print help message.\n"
	"       -i        Disable IP caching.\n"
	"       -k reconfigure|rotate|shutdown|interrupt|kill|debug|check\n"
	"                 Send signal to running copy and exit.\n"
	"       -s        Enable logging to syslog.\n"
	"       -u port   Specify ICP port number (default: %d), disable with 0.\n"
	"       -v        Print version.\n"
	"       -z        Zap disk storage -- deletes all objects in disk cache.\n"
	"       -C        Do not catch fatal signals.\n"
	"       -D        Disable initial DNS tests.\n"
	"       -F        Foreground fast store rebuild.\n"
	"       -R        Do not set REUSEADDR on port.\n"
	"       -U        Unlink expired objects on reload.\n"
	"       -V        Virtual host httpd-accelerator.\n"
	"       -Y        Only return UDP_HIT or UDP_RELOADING during fast reload.\n",
	appname, CACHE_HTTP_PORT, DefaultConfigFile, CACHE_ICP_PORT);
    exit(1);
}
