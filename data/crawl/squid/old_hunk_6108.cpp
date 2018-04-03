static void parse_http_header(HttpHeaderMask * header);
static void free_http_header(HttpHeaderMask * header);

static void
self_destruct(void)
{
    fatalf("Bungled %s line %d: %s",
