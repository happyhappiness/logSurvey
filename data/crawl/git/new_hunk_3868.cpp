
#else

static int host_matches(const char *host, const char *pattern)
{
	if (pattern[0] == '*' && pattern[1] == '.') {
		pattern += 2;
		if (!(host = strchr(host, '.')))
			return 0;
		host++;
	}

	return *host && *pattern && !strcasecmp(host, pattern);
}

static int verify_hostname(X509 *cert, const char *hostname)
{
	int len;
	X509_NAME *subj;
	char cname[1000];

	/* try the common name */
	if (!(subj = X509_get_subject_name(cert)))
		return error("cannot get certificate subject");
	if ((len = X509_NAME_get_text_by_NID(subj, NID_commonName, cname, sizeof(cname))) < 0)
		return error("cannot get certificate common name");
	if (strlen(cname) == (size_t)len && host_matches(hostname, cname))
		return 0;
	return error("certificate owner '%s' does not match hostname '%s'",
		     cname, hostname);
}

static int ssl_socket_connect(struct imap_socket *sock, int use_tls_only, int verify)
{
#if (OPENSSL_VERSION_NUMBER >= 0x10000000L)
