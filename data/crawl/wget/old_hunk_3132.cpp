#define HTTP_STATUS_NOT_IMPLEMENTED	501
#define HTTP_STATUS_BAD_GATEWAY		502
#define HTTP_STATUS_UNAVAILABLE		503

static const char *
head_terminator (const char *hunk, int oldlen, int peeklen)
{
