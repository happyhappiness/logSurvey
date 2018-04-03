 * Currently no powerful encryption is used.
 */
static void
make_pub_auth(cachemgr_request * req) {
    static char buf[1024];
    safe_free(req->pub_auth);
    debug(3) fprintf(stderr, "cmgr: encoding for pub...\n");
