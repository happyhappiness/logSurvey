	free(ctx);
}

#ifndef NO_OPENSSL

/*
 * hexchar() and cram() functions are based on the code from the isync
 * project (http://isync.sf.net/).
 */
static char hexchar(unsigned int b)
{
	return b < 10 ? '0' + b : 'a' + (b - 10);
}

#define ENCODED_SIZE(n) (4*((n+2)/3))
static char *cram(const char *challenge_64, const char *user, const char *pass)
{
	int i, resp_len, encoded_len, decoded_len;
	HMAC_CTX hmac;
	unsigned char hash[16];
	char hex[33];
	char *response, *response_64, *challenge;

	/*
	 * length of challenge_64 (i.e. base-64 encoded string) is a good
	 * enough upper bound for challenge (decoded result).
	 */
	encoded_len = strlen(challenge_64);
	challenge = xmalloc(encoded_len);
	decoded_len = EVP_DecodeBlock((unsigned char *)challenge,
				      (unsigned char *)challenge_64, encoded_len);
	if (decoded_len < 0)
		die("invalid challenge %s", challenge_64);
	HMAC_Init(&hmac, (unsigned char *)pass, strlen(pass), EVP_md5());
	HMAC_Update(&hmac, (unsigned char *)challenge, decoded_len);
	HMAC_Final(&hmac, hash, NULL);
	HMAC_CTX_cleanup(&hmac);

	hex[32] = 0;
	for (i = 0; i < 16; i++) {
		hex[2 * i] = hexchar((hash[i] >> 4) & 0xf);
		hex[2 * i + 1] = hexchar(hash[i] & 0xf);
	}

	/* response: "<user> <digest in hex>" */
	resp_len = strlen(user) + 1 + strlen(hex) + 1;
	response = xmalloc(resp_len);
	sprintf(response, "%s %s", user, hex);

	response_64 = xmalloc(ENCODED_SIZE(resp_len) + 1);
	encoded_len = EVP_EncodeBlock((unsigned char *)response_64,
				      (unsigned char *)response, resp_len);
	if (encoded_len < 0)
		die("EVP_EncodeBlock error");
	response_64[encoded_len] = '\0';
	return (char *)response_64;
}

#else

static char *cram(const char *challenge_64, const char *user, const char *pass)
{
	die("If you want to use CRAM-MD5 authenticate method, "
	    "you have to build git-imap-send with OpenSSL library.");
}

#endif

static int auth_cram_md5(struct imap_store *ctx, struct imap_cmd *cmd, const char *prompt)
{
	int ret;
	char *response;

	response = cram(prompt, server.user, server.pass);

	ret = socket_write(&ctx->imap->buf.sock, response, strlen(response));
	if (ret != strlen(response))
		return error("IMAP error: sending response failed\n");

	free(response);

	return 0;
}

static struct store *imap_open_store(struct imap_server_conf *srvc)
{
	struct imap_store *ctx;
