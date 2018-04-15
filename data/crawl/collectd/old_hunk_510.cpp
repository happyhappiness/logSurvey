};
static int config_keys_num = 2;

#endif /* ifndef APCMAIN */

struct apc_detail_s
{
	float linev;
	float loadpct;
	float bcharge;
	float timeleft;
	float outputv;
	float itemp;
	float battv;
	float linefreq;
};

#define BIG_BUF 4096

/*
 * Subroutine normally called by macro error_abort() to print
 * FATAL ERROR message and supplied error message
 */
static void generic_error_out(const char *file, int line, const char *fmt, ...)
{
	char buf[256];
	va_list arg_ptr;
	int i;

	snprintf(buf, sizeof(buf), _("FATAL ERROR in %s at line %d\n"), file, line);
	i = strlen(buf);
	va_start(arg_ptr, fmt);
	vsnprintf((char *)&buf[i], sizeof(buf) - i, (char *)fmt, arg_ptr);
	va_end(arg_ptr);
	fprintf(stdout, "%s", buf);

	exit(1);
}

/*
 * Read nbytes from the network.
 * It is possible that the total bytes require in several
 * read requests
 */
static int read_nbytes(int fd, char *ptr, int nbytes)
{
	int nleft, nread;

	nleft = nbytes;

	while (nleft > 0) {
		do {
			nread = read(fd, ptr, nleft);
		} while (nread == -1 && (errno == EINTR || errno == EAGAIN));

		if (nread <= 0) {
			return (nread);           /* error, or EOF */
		}

		nleft -= nread;
		ptr += nread;
	}

	return (nbytes - nleft);        /* return >= 0 */
}

/*
 * Write nbytes to the network.
 * It may require several writes.
 */
static int write_nbytes(int fd, void *buf, int buflen)
{
	int nleft;
	int nwritten;
	char *ptr;

	ptr = (char *) buf;

	nleft = buflen;
	while (nleft > 0)
	{
		nwritten = write(fd, ptr, nleft);

		if (nwritten <= 0)
		{
			syslog (LOG_ERR, "Writing to socket failed: %s", strerror (errno));
			return (nwritten);
		}

		nleft -= nwritten;
