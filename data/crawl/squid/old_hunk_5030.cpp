{
    int rc;

    if (ld == NULL) {
#if HAS_URI_SUPPORT
	if (strstr(ldapServer, "://") != NULL) {
