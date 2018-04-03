/*
 * This code is included at the end of sha1dc/sha1.c with the
 * SHA1DC_CUSTOM_TRAILING_INCLUDE_SHA1_C macro.
 */

void git_SHA1DCFinal(unsigned char hash[20], SHA1_CTX *ctx)
{
	if (!SHA1DCFinal(hash, ctx))
