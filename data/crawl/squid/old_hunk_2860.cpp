static void mcast_encode(unsigned int *, size_t, const unsigned int *);
#endif

const char *log_tags[] = {
    "NONE",
    "TCP_HIT",
    "TCP_MISS",
    "TCP_REFRESH_UNMODIFIED",
    "TCP_REFRESH_FAIL", // same tag logged for LOG_TCP_REFRESH_FAIL_OLD and
    "TCP_REFRESH_FAIL", // LOG_TCP_REFRESH_FAIL_ERR for backward-compatibility
    "TCP_REFRESH_MODIFIED",
    "TCP_CLIENT_REFRESH_MISS",
    "TCP_IMS_HIT",
    "TCP_SWAPFAIL_MISS",
    "TCP_NEGATIVE_HIT",
    "TCP_MEM_HIT",
    "TCP_DENIED",
    "TCP_DENIED_REPLY",
    "TCP_OFFLINE_HIT",
#if LOG_TCP_REDIRECTS
    "TCP_REDIRECT",
#endif
    "UDP_HIT",
    "UDP_MISS",
    "UDP_DENIED",
    "UDP_INVALID",
    "UDP_MISS_NOFETCH",
    "ICP_QUERY",
    "LOG_TYPE_MAX"
};

#if USE_FORW_VIA_DB

typedef struct {
    hash_link hash;
    int n;
} fvdb_entry;
static hash_table *via_table = NULL;
static hash_table *forw_table = NULL;
static void fvdbInit();
static void fvdbDumpTable(StoreEntry * e, hash_table * hash);
static void fvdbCount(hash_table * hash, const char *key);
static OBJH fvdbDumpVia;
static OBJH fvdbDumpForw;
static FREE fvdbFreeEntry;
static void fvdbClear(void);
static void fvdbRegisterWithCacheManager();
#endif

int LogfileStatus = LOG_DISABLE;

#if USE_ADAPTATION
bool alLogformatHasAdaptToken = false;
#endif

#if ICAP_CLIENT
bool alLogformatHasIcapToken = false;
#endif

#define LOG_BUF_SZ (MAX_URL<<2)

static const char c2x[] =
    "000102030405060708090a0b0c0d0e0f"
    "101112131415161718191a1b1c1d1e1f"
    "202122232425262728292a2b2c2d2e2f"
    "303132333435363738393a3b3c3d3e3f"
    "404142434445464748494a4b4c4d4e4f"
    "505152535455565758595a5b5c5d5e5f"
    "606162636465666768696a6b6c6d6e6f"
    "707172737475767778797a7b7c7d7e7f"
    "808182838485868788898a8b8c8d8e8f"
    "909192939495969798999a9b9c9d9e9f"
    "a0a1a2a3a4a5a6a7a8a9aaabacadaeaf"
    "b0b1b2b3b4b5b6b7b8b9babbbcbdbebf"
    "c0c1c2c3c4c5c6c7c8c9cacbcccdcecf"
    "d0d1d2d3d4d5d6d7d8d9dadbdcdddedf"
    "e0e1e2e3e4e5e6e7e8e9eaebecedeeef"
    "f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff";

/* log_quote -- URL-style encoding on MIME headers. */

char *
log_quote(const char *header)
{
    int c;
    int i;
    char *buf;
    char *buf_cursor;

    if (header == NULL) {
        buf = static_cast<char *>(xcalloc(1, 1));
        *buf = '\0';
        return buf;
    }

    buf = static_cast<char *>(xcalloc(1, (strlen(header) * 3) + 1));
    buf_cursor = buf;
    /*
     * We escape: \x00-\x1F"#%;<>?{}|\\\\^~`\[\]\x7F-\xFF
     * which is the default escape list for the CPAN Perl5 URI module
     * modulo the inclusion of space (x40) to make the raw logs a bit
     * more readable.
     */

    while ((c = *(const unsigned char *) header++) != '\0') {
#if !OLD_LOG_MIME

        if (c == '\r') {
            *buf_cursor++ = '\\';
            *buf_cursor++ = 'r';
        } else if (c == '\n') {
            *buf_cursor++ = '\\';
            *buf_cursor++ = 'n';
        } else
#endif
            if (c <= 0x1F
                    || c >= 0x7F
                    || c == '%'
#if OLD_LOG_MIME
                    || c == '"'
                    || c == '#'
                    || c == ';'
                    || c == '<'
                    || c == '>'
                    || c == '?'
                    || c == '{'
                    || c == '}'
                    || c == '|'
                    || c == '\\'
                    || c == '^'
                    || c == '~'
                    || c == '`'
#endif
                    || c == '['
                    || c == ']') {
                *buf_cursor++ = '%';
                i = c * 2;
                *buf_cursor++ = c2x[i];
                *buf_cursor++ = c2x[i + 1];
#if !OLD_LOG_MIME

            } else if (c == '\\') {
                *buf_cursor++ = '\\';
                *buf_cursor++ = '\\';
#endif

            } else {
                *buf_cursor++ = (char) c;
            }
    }

    *buf_cursor = '\0';
    return buf;
}

static char *
username_quote(const char *header)
/* copy of log_quote. Bugs there will be found here */
{
    int c;
    int i;
    char *buf;
    char *buf_cursor;

    if (header == NULL) {
        buf = static_cast<char *>(xcalloc(1, 1));
        *buf = '\0';
        return buf;
    }

    buf = static_cast<char *>(xcalloc(1, (strlen(header) * 3) + 1));
    buf_cursor = buf;
    /*
     * We escape: space \x00-\x1F and space (0x40) and \x7F-\xFF
     * to prevent garbage in the logs. CR and LF are also there just in case.
     */

    while ((c = *(const unsigned char *) header++) != '\0') {
        if (c == '\r') {
            *buf_cursor++ = '\\';
            *buf_cursor++ = 'r';
        } else if (c == '\n') {
            *buf_cursor++ = '\\';
            *buf_cursor++ = 'n';
        } else if (c <= 0x1F
                   || c >= 0x7F
                   || c == '%'
                   || c == ' ') {
            *buf_cursor++ = '%';
            i = c * 2;
            *buf_cursor++ = c2x[i];
            *buf_cursor++ = c2x[i + 1];
        } else {
            *buf_cursor++ = (char) c;
        }
    }

    *buf_cursor = '\0';
    return buf;
}

static char *
accessLogFormatName(const char *name)
{
    if (NULL == name)
        return NULL;

    if (name[0] == '\0')
        return NULL;

    return username_quote(name);
}

static char *
log_quoted_string(const char *str)
{
    char *out = (char *)xmalloc(strlen(str) * 2 + 1);
    char *p = out;

    while (*str) {
        int l = strcspn(str, "\"\\\r\n\t");
        memcpy(p, str, l);
        str += l;
        p += l;

        switch (*str) {

        case '\0':
            break;

        case '\r':
            *p++ = '\\';
            *p++ = 'r';
            str++;
            break;

        case '\n':
            *p++ = '\\';
            *p++ = 'n';
            str++;
            break;

        case '\t':
            *p++ = '\\';
            *p++ = 't';
            str++;
            break;

        default:
            *p++ = '\\';
            *p++ = *str;
            str++;
            break;
        }
    }

    *p++ = '\0';
    return out;
}

/*
 * Bytecodes for the configureable logformat stuff
 */
typedef enum {
    LFT_NONE,			/* dummy */
    LFT_STRING,

    LFT_CLIENT_IP_ADDRESS,
    LFT_CLIENT_FQDN,
    LFT_CLIENT_PORT,
#if USE_SQUID_EUI
    LFT_CLIENT_EUI,
#endif

    /*LFT_SERVER_IP_ADDRESS, */
    LFT_SERVER_IP_OR_PEER_NAME,
    /*LFT_SERVER_PORT, */

    LFT_LOCAL_IP,
    LFT_LOCAL_PORT,
    /*LFT_LOCAL_NAME, */
    LFT_PEER_LOCAL_PORT,

    LFT_TIME_SECONDS_SINCE_EPOCH,
    LFT_TIME_SUBSECOND,
    LFT_TIME_LOCALTIME,
    LFT_TIME_GMT,
    LFT_TIME_TO_HANDLE_REQUEST,

    LFT_PEER_RESPONSE_TIME,
    LFT_TOTAL_SERVER_SIDE_RESPONSE_TIME,
    LFT_DNS_WAIT_TIME,

    LFT_REQUEST_HEADER,
    LFT_REQUEST_HEADER_ELEM,
    LFT_REQUEST_ALL_HEADERS,

    LFT_ADAPTED_REQUEST_HEADER,
    LFT_ADAPTED_REQUEST_HEADER_ELEM,
    LFT_ADAPTED_REQUEST_ALL_HEADERS,

    LFT_REPLY_HEADER,
    LFT_REPLY_HEADER_ELEM,
    LFT_REPLY_ALL_HEADERS,

    LFT_USER_NAME,
    LFT_USER_LOGIN,
    LFT_USER_IDENT,
    /*LFT_USER_REALM, */
    /*LFT_USER_SCHEME, */
    LFT_USER_EXTERNAL,

    LFT_HTTP_SENT_STATUS_CODE_OLD_30,
    LFT_HTTP_SENT_STATUS_CODE,
    LFT_HTTP_RECEIVED_STATUS_CODE,
    /*LFT_HTTP_STATUS, */
    LFT_HTTP_BODY_BYTES_READ,

    LFT_SQUID_STATUS,
    LFT_SQUID_ERROR,
    LFT_SQUID_ERROR_DETAIL,
    LFT_SQUID_HIERARCHY,

    LFT_MIME_TYPE,

    LFT_REQUEST_METHOD,
    LFT_REQUEST_URI,
    LFT_REQUEST_URLPATH,
    /*LFT_REQUEST_QUERY, * // * this is not needed. see strip_query_terms */
    LFT_REQUEST_VERSION,

    LFT_REQUEST_SIZE_TOTAL,
    /*LFT_REQUEST_SIZE_LINE, */
    LFT_REQUEST_SIZE_HEADERS,
    /*LFT_REQUEST_SIZE_BODY, */
    /*LFT_REQUEST_SIZE_BODY_NO_TE, */

    LFT_REPLY_SIZE_TOTAL,
    LFT_REPLY_HIGHOFFSET,
    LFT_REPLY_OBJECTSIZE,
    /*LFT_REPLY_SIZE_LINE, */
    LFT_REPLY_SIZE_HEADERS,
    /*LFT_REPLY_SIZE_BODY, */
    /*LFT_REPLY_SIZE_BODY_NO_TE, */

    LFT_TAG,
    LFT_IO_SIZE_TOTAL,
    LFT_EXT_LOG,

    LFT_SEQUENCE_NUMBER,

#if USE_ADAPTATION
    LTF_ADAPTATION_SUM_XACT_TIMES,
    LTF_ADAPTATION_ALL_XACT_TIMES,
#endif

#if ICAP_CLIENT

    LFT_ICAP_TOTAL_TIME,
    LFT_ICAP_LAST_MATCHED_HEADER,
    LFT_ICAP_LAST_MATCHED_HEADER_ELEM,
    LFT_ICAP_LAST_MATCHED_ALL_HEADERS,

    LFT_ICAP_ADDR,
    LFT_ICAP_SERV_NAME,
    LFT_ICAP_REQUEST_URI,
    LFT_ICAP_REQUEST_METHOD,
    LFT_ICAP_BYTES_SENT,
    LFT_ICAP_BYTES_READ,
    LFT_ICAP_BODY_BYTES_READ,

    LFT_ICAP_REQ_HEADER,
    LFT_ICAP_REQ_HEADER_ELEM,
    LFT_ICAP_REQ_ALL_HEADERS,

    LFT_ICAP_REP_HEADER,
    LFT_ICAP_REP_HEADER_ELEM,
    LFT_ICAP_REP_ALL_HEADERS,

    LFT_ICAP_TR_RESPONSE_TIME,
    LFT_ICAP_IO_TIME,
    LFT_ICAP_OUTCOME,
    LFT_ICAP_STATUS_CODE,
#endif

    LFT_PERCENT			/* special string cases for escaped chars */
} logformat_bcode_t;

enum log_quote {
    LOG_QUOTE_NONE = 0,
    LOG_QUOTE_QUOTES,
    LOG_QUOTE_BRAKETS,
    LOG_QUOTE_URL,
    LOG_QUOTE_RAW
};

/* FIXME: public class so we can pre-define its type. */
class logformat_token
{
public:
    logformat_bcode_t type;
    union {
        char *string;

        struct {
            char *header;
            char *element;
            char separator;
        } header;
        char *timespec;
    } data;
    unsigned char width;
    unsigned char precision;
    enum log_quote quote;
    unsigned int left:1;
    unsigned int space:1;
    unsigned int zero:1;
    int divisor;
    logformat_token *next;	/* todo: move from linked list to array */
};

struct logformat_token_table_entry {
    const char *config;
    logformat_bcode_t token_type;
    int options;
};

struct logformat_token_table_entry logformat_token_table[] = {

    {">a", LFT_CLIENT_IP_ADDRESS},
    {">p", LFT_CLIENT_PORT},
    {">A", LFT_CLIENT_FQDN},
#if USE_SQUID_EUI
    {">eui", LFT_CLIENT_EUI},
#endif

    /*{ "<a", LFT_SERVER_IP_ADDRESS }, */
    /*{ "<p", LFT_SERVER_PORT }, */
    {"<A", LFT_SERVER_IP_OR_PEER_NAME},

    /* {"oa", LFT_OUTGOING_IP}, */
    /* {"ot", LFT_OUTGOING_TOS}, */

    {"la", LFT_LOCAL_IP},
    {"lp", LFT_LOCAL_PORT},
    /*{ "lA", LFT_LOCAL_NAME }, */
    {"<lp", LFT_PEER_LOCAL_PORT},

    {"ts", LFT_TIME_SECONDS_SINCE_EPOCH},
    {"tu", LFT_TIME_SUBSECOND},
    {"tl", LFT_TIME_LOCALTIME},
    {"tg", LFT_TIME_GMT},
    {"tr", LFT_TIME_TO_HANDLE_REQUEST},

    {"<pt", LFT_PEER_RESPONSE_TIME},
    {"<tt", LFT_TOTAL_SERVER_SIDE_RESPONSE_TIME},
    {"dt", LFT_DNS_WAIT_TIME},

    {">ha", LFT_ADAPTED_REQUEST_HEADER},
    {">ha", LFT_ADAPTED_REQUEST_ALL_HEADERS},
    {">h", LFT_REQUEST_HEADER},
    {">h", LFT_REQUEST_ALL_HEADERS},
    {"<h", LFT_REPLY_HEADER},
    {"<h", LFT_REPLY_ALL_HEADERS},

    {"un", LFT_USER_NAME},
    {"ul", LFT_USER_LOGIN},
    /*{ "ur", LFT_USER_REALM }, */
    /*{ "us", LFT_USER_SCHEME }, */
    {"ui", LFT_USER_IDENT},
    {"ue", LFT_USER_EXTERNAL},

    {"Hs", LFT_HTTP_SENT_STATUS_CODE_OLD_30},
    {">Hs", LFT_HTTP_SENT_STATUS_CODE},
    {"<Hs", LFT_HTTP_RECEIVED_STATUS_CODE},
    /*{ "Ht", LFT_HTTP_STATUS }, */
    {"<bs", LFT_HTTP_BODY_BYTES_READ},

    {"Ss", LFT_SQUID_STATUS},
    { "err_code", LFT_SQUID_ERROR },
    { "err_detail", LFT_SQUID_ERROR_DETAIL },
    {"Sh", LFT_SQUID_HIERARCHY},

    {"mt", LFT_MIME_TYPE},

    {"rm", LFT_REQUEST_METHOD},
    {"ru", LFT_REQUEST_URI},	/* doesn't include the query-string */
    {"rp", LFT_REQUEST_URLPATH},	/* doesn't include the host */
    /* { "rq", LFT_REQUEST_QUERY }, * /     / * the query-string, INCLUDING the leading ? */
    {">v", LFT_REQUEST_VERSION},
    {"rv", LFT_REQUEST_VERSION},

    { ">st", LFT_REQUEST_SIZE_TOTAL },
    /*{ ">sl", LFT_REQUEST_SIZE_LINE }, * / / * the request line "GET ... " */
    { ">sh", LFT_REQUEST_SIZE_HEADERS },
    /*{ ">sb", LFT_REQUEST_SIZE_BODY }, */
    /*{ ">sB", LFT_REQUEST_SIZE_BODY_NO_TE }, */

    {"<st", LFT_REPLY_SIZE_TOTAL},
    {"<sH", LFT_REPLY_HIGHOFFSET},
    {"<sS", LFT_REPLY_OBJECTSIZE},
    /*{ "<sl", LFT_REPLY_SIZE_LINE }, * /   / * the reply line (protocol, code, text) */
    { "<sh", LFT_REPLY_SIZE_HEADERS },
    /*{ "<sb", LFT_REPLY_SIZE_BODY }, */
    /*{ "<sB", LFT_REPLY_SIZE_BODY_NO_TE }, */

    {"et", LFT_TAG},
    {"st", LFT_IO_SIZE_TOTAL},
    {"ea", LFT_EXT_LOG},
    {"sn", LFT_SEQUENCE_NUMBER},

    {"%", LFT_PERCENT},

#if USE_ADAPTATION
    {"adapt::all_trs", LTF_ADAPTATION_ALL_XACT_TIMES},
    {"adapt::sum_trs", LTF_ADAPTATION_SUM_XACT_TIMES},
#endif

#if ICAP_CLIENT
    {"icap::tt", LFT_ICAP_TOTAL_TIME},
    {"icap::<last_h", LFT_ICAP_LAST_MATCHED_HEADER},

    {"icap::<A",  LFT_ICAP_ADDR},
    {"icap::<service_name",  LFT_ICAP_SERV_NAME},
    {"icap::ru",  LFT_ICAP_REQUEST_URI},
    {"icap::rm",  LFT_ICAP_REQUEST_METHOD},
    {"icap::>st",  LFT_ICAP_BYTES_SENT},
    {"icap::<st",  LFT_ICAP_BYTES_READ},
    {"icap::<bs", LFT_ICAP_BODY_BYTES_READ},

    {"icap::>h",  LFT_ICAP_REQ_HEADER},
    {"icap::<h",  LFT_ICAP_REP_HEADER},

    {"icap::tr",  LFT_ICAP_TR_RESPONSE_TIME},
    {"icap::tio",  LFT_ICAP_IO_TIME},
    {"icap::to",  LFT_ICAP_OUTCOME},
    {"icap::Hs",  LFT_ICAP_STATUS_CODE},
#endif

    {NULL, LFT_NONE}		/* this must be last */
};

static void
accessLogCustom(AccessLogEntry * al, customlog * log)
{
    logformat *lf;
    Logfile *logfile;
    logformat_token *fmt;
    static MemBuf mb;
    char tmp[1024];
    String sb;

    mb.reset();

    lf = log->logFormat;
    logfile = log->logfile;

    for (fmt = lf->format; fmt != NULL; fmt = fmt->next) {	/* for each token */
        const char *out = NULL;
        int quote = 0;
        long int outint = 0;
        int doint = 0;
        int dofree = 0;
        int64_t outoff = 0;
        int dooff = 0;

        switch (fmt->type) {

        case LFT_NONE:
            out = "";
            break;

        case LFT_STRING:
            out = fmt->data.string;
            break;

        case LFT_CLIENT_IP_ADDRESS:
            if (al->cache.caddr.IsNoAddr()) // e.g., ICAP OPTIONS lack client
                out = "-";
            else
                out = al->cache.caddr.NtoA(tmp,1024);
            break;

        case LFT_CLIENT_FQDN:
            if (al->cache.caddr.IsAnyAddr()) // e.g., ICAP OPTIONS lack client
                out = "-";
            else
                out = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);
            if (!out) {
                out = al->cache.caddr.NtoA(tmp,1024);
            }

            break;

        case LFT_CLIENT_PORT:
            if (al->request) {
                outint = al->request->client_addr.GetPort();
                doint = 1;
            }
            break;

#if USE_SQUID_EUI
        case LFT_CLIENT_EUI:
            if (al->request) {
                if (al->cache.caddr.IsIPv4())
                    al->request->client_eui48.encode(tmp, 1024);
                else
                    al->request->client_eui64.encode(tmp, 1024);
                out = tmp;
            }
            break;
#endif

            /* case LFT_SERVER_IP_ADDRESS: */

        case LFT_SERVER_IP_OR_PEER_NAME:
            out = al->hier.host;

            break;

            /* case LFT_SERVER_PORT: */

        case LFT_LOCAL_IP:
            if (al->request) {
                out = al->request->my_addr.NtoA(tmp,1024);
            }

            break;

        case LFT_LOCAL_PORT:
            if (al->request) {
                outint = al->request->my_addr.GetPort();
                doint = 1;
            }

            break;

        case LFT_PEER_LOCAL_PORT:
            if (al->hier.peer_local_port) {
                outint = al->hier.peer_local_port;
                doint = 1;
            }

            break;

        case LFT_TIME_SECONDS_SINCE_EPOCH:
            // some platforms store time in 32-bit, some 64-bit...
            outoff = static_cast<int64_t>(current_time.tv_sec);
            dooff = 1;
            break;

        case LFT_TIME_SUBSECOND:
            outint = current_time.tv_usec / fmt->divisor;
            doint = 1;
            break;


        case LFT_TIME_LOCALTIME:

        case LFT_TIME_GMT: {
            const char *spec;

            struct tm *t;
            spec = fmt->data.timespec;

            if (fmt->type == LFT_TIME_LOCALTIME) {
                if (!spec)
                    spec = "%d/%b/%Y:%H:%M:%S %z";
                t = localtime(&squid_curtime);
            } else {
                if (!spec)
                    spec = "%d/%b/%Y:%H:%M:%S";

                t = gmtime(&squid_curtime);
            }

            strftime(tmp, sizeof(tmp), spec, t);

            out = tmp;
        }

        break;

        case LFT_TIME_TO_HANDLE_REQUEST:
            outint = al->cache.msec;
            doint = 1;
            break;

        case LFT_PEER_RESPONSE_TIME:
            if (al->hier.peer_response_time < 0) {
                out = "-";
            } else {
                outoff = al->hier.peer_response_time;
                dooff = 1;
            }
            break;

        case LFT_TOTAL_SERVER_SIDE_RESPONSE_TIME:
            if (al->hier.total_response_time < 0) {
                out = "-";
            } else {
                outoff = al->hier.total_response_time;
                dooff = 1;
            }
            break;

        case LFT_DNS_WAIT_TIME:
            if (al->request && al->request->dnsWait >= 0) {
                outint = al->request->dnsWait;
                doint = 1;
            }
            break;

        case LFT_REQUEST_HEADER:

            if (al->request)
                sb = al->request->header.getByName(fmt->data.header.header);

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_ADAPTED_REQUEST_HEADER:

            if (al->request)
                sb = al->adapted_request->header.getByName(fmt->data.header.header);

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_REPLY_HEADER:
            if (al->reply)
                sb = al->reply->header.getByName(fmt->data.header.header);

            out = sb.termedBuf();

            quote = 1;

            break;

#if USE_ADAPTATION
        case LTF_ADAPTATION_SUM_XACT_TIMES:
            if (al->request) {
                Adaptation::History::Pointer ah = al->request->adaptHistory();
                if (ah != NULL)
                    ah->sumLogString(fmt->data.string, sb);
                out = sb.termedBuf();
            }
            break;

        case LTF_ADAPTATION_ALL_XACT_TIMES:
            if (al->request) {
                Adaptation::History::Pointer ah = al->request->adaptHistory();
                if (ah != NULL)
                    ah->allLogString(fmt->data.string, sb);
                out = sb.termedBuf();
            }
            break;
#endif

#if ICAP_CLIENT
        case LFT_ICAP_LAST_MATCHED_HEADER:
            if (al->request) {
                Adaptation::Icap::History::Pointer ih = al->request->icapHistory();
                if (ih != NULL)
                    sb = ih->mergeOfIcapHeaders.getByName(fmt->data.header.header);
            }

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_ICAP_LAST_MATCHED_HEADER_ELEM:
            if (al->request) {
                Adaptation::Icap::History::Pointer ih = al->request->icapHistory();
                if (ih != NULL)
                    sb = ih->mergeOfIcapHeaders.getByNameListMember(fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);
            }

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_ICAP_LAST_MATCHED_ALL_HEADERS:
            out = al->headers.icap;

            quote = 1;

            break;

        case LFT_ICAP_ADDR:
            if (!out)
                out = al->icap.hostAddr.NtoA(tmp,1024);
            break;

        case LFT_ICAP_SERV_NAME:
            out = al->icap.serviceName.termedBuf();
            break;

        case LFT_ICAP_REQUEST_URI:
            out = al->icap.reqUri.termedBuf();
            break;

        case LFT_ICAP_REQUEST_METHOD:
            out = Adaptation::Icap::ICAP::methodStr(al->icap.reqMethod);
            break;

        case LFT_ICAP_BYTES_SENT:
            outoff = al->icap.bytesSent;
            dooff = 1;
            break;

        case LFT_ICAP_BYTES_READ:
            outoff = al->icap.bytesRead;
            dooff = 1;
            break;

        case LFT_ICAP_BODY_BYTES_READ:
            if (al->icap.bodyBytesRead >= 0) {
                outoff = al->icap.bodyBytesRead;
                dooff = 1;
            }
            // else if icap.bodyBytesRead < 0, we do not have any http data,
            // so just print a "-" (204 responses etc)
            break;

        case LFT_ICAP_REQ_HEADER:
            if (NULL != al->icap.request) {
                sb = al->icap.request->header.getByName(fmt->data.header.header);
                out = sb.termedBuf();
                quote = 1;
            }
            break;

        case LFT_ICAP_REQ_HEADER_ELEM:
            if (al->request)
                sb = al->icap.request->header.getByNameListMember(fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_ICAP_REQ_ALL_HEADERS:
            if (al->icap.request) {
                HttpHeaderPos pos = HttpHeaderInitPos;
                while (const HttpHeaderEntry *e = al->icap.request->header.getEntry(&pos)) {
                    sb.append(e->name);
                    sb.append(": ");
                    sb.append(e->value);
                    sb.append("\r\n");
                }
                out = sb.termedBuf();
                quote = 1;
            }
            break;

        case LFT_ICAP_REP_HEADER:
            if (NULL != al->icap.reply) {
                sb = al->icap.reply->header.getByName(fmt->data.header.header);
                out = sb.termedBuf();
                quote = 1;
            }
            break;

        case LFT_ICAP_REP_HEADER_ELEM:
            if (NULL != al->icap.reply)
                sb = al->icap.reply->header.getByNameListMember(fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_ICAP_REP_ALL_HEADERS:
            if (al->icap.reply) {
                HttpHeaderPos pos = HttpHeaderInitPos;
                while (const HttpHeaderEntry *e = al->icap.reply->header.getEntry(&pos)) {
                    sb.append(e->name);
                    sb.append(": ");
                    sb.append(e->value);
                    sb.append("\r\n");
                }
                out = sb.termedBuf();
                quote = 1;
            }
            break;

        case LFT_ICAP_TR_RESPONSE_TIME:
            outint = al->icap.trTime;
            doint = 1;
            break;

        case LFT_ICAP_IO_TIME:
            outint = al->icap.ioTime;
            doint = 1;
            break;

        case LFT_ICAP_STATUS_CODE:
            outint = al->icap.resStatus;
            doint  = 1;
            break;

        case LFT_ICAP_OUTCOME:
            out = al->icap.outcome;
            break;

        case LFT_ICAP_TOTAL_TIME:
            outint = al->icap.processingTime;
            doint = 1;
            break;
#endif
        case LFT_REQUEST_HEADER_ELEM:
            if (al->request)
                sb = al->request->header.getByNameListMember(fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_ADAPTED_REQUEST_HEADER_ELEM:
            if (al->adapted_request)
                sb = al->adapted_request->header.getByNameListMember(fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_REPLY_HEADER_ELEM:
            if (al->reply)
                sb = al->reply->header.getByNameListMember(fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);

            out = sb.termedBuf();

            quote = 1;

            break;

        case LFT_REQUEST_ALL_HEADERS:
            out = al->headers.request;

            quote = 1;

            break;

        case LFT_ADAPTED_REQUEST_ALL_HEADERS:
            out = al->headers.adapted_request;

            quote = 1;

            break;

        case LFT_REPLY_ALL_HEADERS:
            out = al->headers.reply;

            quote = 1;

            break;

        case LFT_USER_NAME:
            out = accessLogFormatName(al->cache.authuser);

            if (!out)
                out = accessLogFormatName(al->cache.extuser);

#if USE_SSL

            if (!out)
                out = accessLogFormatName(al->cache.ssluser);

#endif

            if (!out)
                out = accessLogFormatName(al->cache.rfc931);

            dofree = 1;

            break;

        case LFT_USER_LOGIN:
            out = accessLogFormatName(al->cache.authuser);

            dofree = 1;

            break;

        case LFT_USER_IDENT:
            out = accessLogFormatName(al->cache.rfc931);

            dofree = 1;

            break;

        case LFT_USER_EXTERNAL:
            out = accessLogFormatName(al->cache.extuser);

            dofree = 1;

            break;

            /* case LFT_USER_REALM: */
            /* case LFT_USER_SCHEME: */

            // the fmt->type can not be LFT_HTTP_SENT_STATUS_CODE_OLD_30
            // but compiler complains if ommited
        case LFT_HTTP_SENT_STATUS_CODE_OLD_30:
        case LFT_HTTP_SENT_STATUS_CODE:
            outint = al->http.code;

            doint = 1;

            break;

        case LFT_HTTP_RECEIVED_STATUS_CODE:
            if (al->hier.peer_reply_status == HTTP_STATUS_NONE) {
                out = "-";
            } else {
                outint = al->hier.peer_reply_status;
                doint = 1;
            }
            break;
            /* case LFT_HTTP_STATUS:
             *           out = statusline->text;
             *     quote = 1;
             *     break;
             */
        case LFT_HTTP_BODY_BYTES_READ:
            if (al->hier.bodyBytesRead >= 0) {
                outoff = al->hier.bodyBytesRead;
                dooff = 1;
            }
            // else if hier.bodyBytesRead < 0 we did not have any data exchange with
            // a peer server so just print a "-" (eg requests served from cache,
            // or internal error messages).
            break;

        case LFT_SQUID_STATUS:
            if (al->http.timedout || al->http.aborted) {
                snprintf(tmp, sizeof(tmp), "%s%s", log_tags[al->cache.code],
                         al->http.statusSfx());
                out = tmp;
            } else {
                out = log_tags[al->cache.code];
            }

            break;

        case LFT_SQUID_ERROR:
            if (al->request && al->request->errType != ERR_NONE)
                out = errorPageName(al->request->errType);
            break;

        case LFT_SQUID_ERROR_DETAIL:
            if (al->request && al->request->errDetail != ERR_DETAIL_NONE) {
                if (al->request->errDetail > ERR_DETAIL_START  &&
                        al->request->errDetail < ERR_DETAIL_MAX)
                    out = errorDetailName(al->request->errDetail);
                else {
                    if (al->request->errDetail >= ERR_DETAIL_EXCEPTION_START)
                        snprintf(tmp, sizeof(tmp), "%s=0x%X",
                                 errorDetailName(al->request->errDetail), (uint32_t) al->request->errDetail);
                    else
                        snprintf(tmp, sizeof(tmp), "%s=%d",
                                 errorDetailName(al->request->errDetail), al->request->errDetail);
                    out = tmp;
                }
            }
            break;

        case LFT_SQUID_HIERARCHY:
            if (al->hier.ping.timedout)
                mb.append("TIMEOUT_", 8);

            out = hier_code_str[al->hier.code];

            break;

        case LFT_MIME_TYPE:
            out = al->http.content_type;

            break;

        case LFT_REQUEST_METHOD:
            out = al->_private.method_str;

            break;

        case LFT_REQUEST_URI:
            out = al->url;

            break;

        case LFT_REQUEST_URLPATH:
            if (al->request) {
                out = al->request->urlpath.termedBuf();
                quote = 1;
            }
            break;

        case LFT_REQUEST_VERSION:
            snprintf(tmp, sizeof(tmp), "%d.%d", (int) al->http.version.major, (int) al->http.version.minor);
            out = tmp;
            break;

        case LFT_REQUEST_SIZE_TOTAL:
            outoff = al->cache.requestSize;
            dooff = 1;
            break;

            /*case LFT_REQUEST_SIZE_LINE: */
        case LFT_REQUEST_SIZE_HEADERS:
            outoff = al->cache.requestHeadersSize;
            dooff =1;
            break;
            /*case LFT_REQUEST_SIZE_BODY: */
            /*case LFT_REQUEST_SIZE_BODY_NO_TE: */

        case LFT_REPLY_SIZE_TOTAL:
            outoff = al->cache.replySize;
            dooff = 1;
            break;

        case LFT_REPLY_HIGHOFFSET:
            outoff = al->cache.highOffset;

            dooff = 1;

            break;

        case LFT_REPLY_OBJECTSIZE:
            outoff = al->cache.objectSize;

            dooff = 1;

            break;

            /*case LFT_REPLY_SIZE_LINE: */
        case LFT_REPLY_SIZE_HEADERS:
            outint = al->cache.replyHeadersSize;
            doint = 1;
            break;
            /*case LFT_REPLY_SIZE_BODY: */
            /*case LFT_REPLY_SIZE_BODY_NO_TE: */

        case LFT_TAG:
            if (al->request)
                out = al->request->tag.termedBuf();

            quote = 1;

            break;

        case LFT_IO_SIZE_TOTAL:
            outint = al->cache.requestSize + al->cache.replySize;
            doint = 1;
            break;

        case LFT_EXT_LOG:
            if (al->request)
                out = al->request->extacl_log.termedBuf();

            quote = 1;

            break;

        case LFT_SEQUENCE_NUMBER:
            outoff = logfile->sequence_number;
            dooff = 1;
            break;

        case LFT_PERCENT:
            out = "%";

            break;
        }

        if (dooff) {
            snprintf(tmp, sizeof(tmp), "%0*" PRId64, fmt->zero ? (int) fmt->width : 0, outoff);
            out = tmp;

        } else if (doint) {
            snprintf(tmp, sizeof(tmp), "%0*ld", fmt->zero ? (int) fmt->width : 0, outint);
            out = tmp;
        }

        if (out && *out) {
            if (quote || fmt->quote != LOG_QUOTE_NONE) {
                char *newout = NULL;
                int newfree = 0;

                switch (fmt->quote) {

                case LOG_QUOTE_NONE:
                    newout = rfc1738_escape_unescaped(out);
                    break;

                case LOG_QUOTE_QUOTES:
                    newout = log_quoted_string(out);
                    newfree = 1;
                    break;

                case LOG_QUOTE_BRAKETS:
                    newout = log_quote(out);
                    newfree = 1;
                    break;

                case LOG_QUOTE_URL:
                    newout = rfc1738_escape(out);
                    break;

                case LOG_QUOTE_RAW:
                    break;
                }

                if (newout) {
                    if (dofree)
                        safe_free(out);

                    out = newout;

                    dofree = newfree;
                }
            }

            if (fmt->width) {
                if (fmt->left)
                    mb.Printf("%-*s", (int) fmt->width, out);
                else
                    mb.Printf("%*s", (int) fmt->width, out);
            } else
                mb.append(out, strlen(out));
        } else {
            mb.append("-", 1);
        }

        if (fmt->space)
            mb.append(" ", 1);

        sb.clean();

        if (dofree)
            safe_free(out);
    }

    logfilePrintf(logfile, "%s\n", mb.buf);
}

/* parses a single token. Returns the token length in characters,
 * and fills in the lt item with the token information.
 * def is for sure null-terminated
 */
static int
accessLogGetNewLogFormatToken(logformat_token * lt, char *def, enum log_quote *quote)
{
    char *cur = def;

    struct logformat_token_table_entry *lte;
    int l;

    memset(lt, 0, sizeof(*lt));
    l = strcspn(cur, "%");

    if (l > 0) {
        char *cp;
        /* it's a string for sure, until \0 or the next % */
        cp = (char *)xmalloc(l + 1);
        xstrncpy(cp, cur, l + 1);
        lt->type = LFT_STRING;
        lt->data.string = cp;

        while (l > 0) {
            switch (*cur) {

            case '"':

                if (*quote == LOG_QUOTE_NONE)
                    *quote = LOG_QUOTE_QUOTES;
                else if (*quote == LOG_QUOTE_QUOTES)
                    *quote = LOG_QUOTE_NONE;

                break;

            case '[':
                if (*quote == LOG_QUOTE_NONE)
                    *quote = LOG_QUOTE_BRAKETS;

                break;

            case ']':
                if (*quote == LOG_QUOTE_BRAKETS)
                    *quote = LOG_QUOTE_NONE;

                break;
            }

            cur++;
            l--;
        }

        goto done;
    }

    if (!*cur)
        goto done;

    cur++;

    switch (*cur) {

    case '"':
        lt->quote = LOG_QUOTE_QUOTES;
        cur++;
        break;

    case '\'':
        lt->quote = LOG_QUOTE_RAW;
        cur++;
        break;

    case '[':
        lt->quote = LOG_QUOTE_BRAKETS;
        cur++;
        break;

    case '#':
        lt->quote = LOG_QUOTE_URL;
        cur++;
        break;

    default:
        lt->quote = *quote;
        break;
    }

    if (*cur == '-') {
        lt->left = 1;
        cur++;
    }

    if (*cur == '0') {
        lt->zero = 1;
        cur++;
    }

    if (xisdigit(*cur))
        lt->width = strtol(cur, &cur, 10);

    if (*cur == '.')
        lt->precision = strtol(cur + 1, &cur, 10);

    if (*cur == '{') {
        char *cp;
        cur++;
        l = strcspn(cur, "}");
        cp = (char *)xmalloc(l + 1);
        xstrncpy(cp, cur, l + 1);
        lt->data.string = cp;
        cur += l;

        if (*cur == '}')
            cur++;
    }

    // For upward compatibility, assume "http::" prefix as default prefix
    // for all log access formating codes, except those starting
    // from "icap::", "adapt::" and "%"
    if (strncmp(cur,"http::", 6) == 0 &&
            strncmp(cur+6, "icap::", 6) != 0  &&
            strncmp(cur+6, "adapt::", 12) != 0 && *(cur+6) != '%' ) {
        cur += 6;
    }

    lt->type = LFT_NONE;

    for (lte = logformat_token_table; lte->config != NULL; lte++) {
        if (strncmp(lte->config, cur, strlen(lte->config)) == 0) {
            lt->type = lte->token_type;
            cur += strlen(lte->config);
            break;
        }
    }

    if (lt->type == LFT_NONE) {
        fatalf("Can't parse configuration token: '%s'\n",
               def);
    }

    if (*cur == ' ') {
        lt->space = 1;
        cur++;
    }

done:

    switch (lt->type) {

#if ICAP_CLIENT
    case LFT_ICAP_LAST_MATCHED_HEADER:

    case LFT_ICAP_REQ_HEADER:

    case LFT_ICAP_REP_HEADER:
#endif

    case LFT_ADAPTED_REQUEST_HEADER:

    case LFT_REQUEST_HEADER:

    case LFT_REPLY_HEADER:

        if (lt->data.string) {
            char *header = lt->data.string;
            char *cp = strchr(header, ':');

            if (cp) {
                *cp++ = '\0';

                if (*cp == ',' || *cp == ';' || *cp == ':')
                    lt->data.header.separator = *cp++;
                else
                    lt->data.header.separator = ',';

                lt->data.header.element = cp;

                switch (lt->type) {
                case LFT_REQUEST_HEADER:
                    lt->type = LFT_REQUEST_HEADER_ELEM;
                    break;

                case LFT_ADAPTED_REQUEST_HEADER:
                    lt->type = LFT_ADAPTED_REQUEST_HEADER_ELEM;
                    break;

                case LFT_REPLY_HEADER:
                    lt->type = LFT_REPLY_HEADER_ELEM;
                    break;
#if ICAP_CLIENT
                case LFT_ICAP_LAST_MATCHED_HEADER:
                    lt->type = LFT_ICAP_LAST_MATCHED_HEADER_ELEM;
                    break;
                case LFT_ICAP_REQ_HEADER:
                    lt->type = LFT_ICAP_REQ_HEADER_ELEM;
                    break;
                case LFT_ICAP_REP_HEADER:
                    lt->type = LFT_ICAP_REP_HEADER_ELEM;
                    break;
#endif
                default:
                    break;
                }
            }

            lt->data.header.header = header;
        } else {
            switch (lt->type) {
            case LFT_REQUEST_HEADER:
                lt->type = LFT_REQUEST_ALL_HEADERS;
                break;

            case LFT_ADAPTED_REQUEST_HEADER:
                lt->type = LFT_ADAPTED_REQUEST_ALL_HEADERS;
                break;

            case LFT_REPLY_HEADER:
                lt->type = LFT_REPLY_ALL_HEADERS;
                break;
#if ICAP_CLIENT
            case LFT_ICAP_LAST_MATCHED_HEADER:
                lt->type = LFT_ICAP_LAST_MATCHED_ALL_HEADERS;
                break;
            case LFT_ICAP_REQ_HEADER:
                lt->type = LFT_ICAP_REQ_ALL_HEADERS;
                break;
            case LFT_ICAP_REP_HEADER:
                lt->type = LFT_ICAP_REP_ALL_HEADERS;
                break;
#endif
            default:
                break;
            }
            Config.onoff.log_mime_hdrs = 1;
        }

        break;

    case LFT_CLIENT_FQDN:
        Config.onoff.log_fqdn = 1;
        break;

    case LFT_TIME_SUBSECOND:
        lt->divisor = 1000;

        if (lt->precision) {
            int i;
            lt->divisor = 1000000;

            for (i = lt->precision; i > 1; i--)
                lt->divisor /= 10;

            if (!lt->divisor)
                lt->divisor = 0;
        }

        break;

    case LFT_HTTP_SENT_STATUS_CODE_OLD_30:
        debugs(46, 0, "WARNING: the \"Hs\" formating code is deprecated use the \">Hs\" instead");
        lt->type = LFT_HTTP_SENT_STATUS_CODE;
        break;
    default:
        break;
    }

    return (cur - def);
}

int
accessLogParseLogFormat(logformat_token ** fmt, char *def)
{
    char *cur, *eos;
    logformat_token *new_lt, *last_lt;
    enum log_quote quote = LOG_QUOTE_NONE;

    debugs(46, 2, "accessLogParseLogFormat: got definition '" << def << "'");

    /* very inefficent parser, but who cares, this needs to be simple */
    /* First off, let's tokenize, we'll optimize in a second pass.
     * A token can either be a %-prefixed sequence (usually a dynamic
     * token but it can be an escaped sequence), or a string. */
    cur = def;
    eos = def + strlen(def);
    *fmt = new_lt = last_lt = (logformat_token *)xmalloc(sizeof(logformat_token));
    cur += accessLogGetNewLogFormatToken(new_lt, cur, &quote);

    while (cur < eos) {
        new_lt = (logformat_token *)xmalloc(sizeof(logformat_token));
        last_lt->next = new_lt;
        last_lt = new_lt;
        cur += accessLogGetNewLogFormatToken(new_lt, cur, &quote);
    }

    return 1;
}

void
accessLogDumpLogFormat(StoreEntry * entry, const char *name, logformat * definitions)
{
    logformat_token *t;
    logformat *format;

    struct logformat_token_table_entry *te;
    debugs(46, 4, "accessLogDumpLogFormat called");

    for (format = definitions; format; format = format->next) {
        debugs(46, 3, "Dumping logformat definition for " << format->name);
        storeAppendPrintf(entry, "logformat %s ", format->name);

        for (t = format->format; t; t = t->next) {
            if (t->type == LFT_STRING)
                storeAppendPrintf(entry, "%s", t->data.string);
            else {
                char argbuf[256];
                char *arg = NULL;
                logformat_bcode_t type = t->type;

                switch (type) {
                    /* special cases */

                case LFT_STRING:
                    break;
#if ICAP_CLIENT
                case LFT_ICAP_LAST_MATCHED_HEADER_ELEM:
                case LFT_ICAP_REQ_HEADER_ELEM:
                case LFT_ICAP_REP_HEADER_ELEM:
#endif
                case LFT_REQUEST_HEADER_ELEM:
                case LFT_ADAPTED_REQUEST_HEADER_ELEM:
                case LFT_REPLY_HEADER_ELEM:

                    if (t->data.header.separator != ',')
                        snprintf(argbuf, sizeof(argbuf), "%s:%c%s", t->data.header.header, t->data.header.separator, t->data.header.element);
                    else
                        snprintf(argbuf, sizeof(argbuf), "%s:%s", t->data.header.header, t->data.header.element);

                    arg = argbuf;

                    switch (type) {
                    case LFT_REQUEST_HEADER_ELEM:
                        type = LFT_REQUEST_HEADER_ELEM;
                        break;
                    case LFT_ADAPTED_REQUEST_HEADER_ELEM:
                        type = LFT_ADAPTED_REQUEST_HEADER_ELEM;
                        break;
                    case LFT_REPLY_HEADER_ELEM:
                        type = LFT_REPLY_HEADER_ELEM;
                        break;
#if ICAP_CLIENT
                    case LFT_ICAP_LAST_MATCHED_HEADER_ELEM:
                        type = LFT_ICAP_LAST_MATCHED_HEADER;
                        break;
                    case LFT_ICAP_REQ_HEADER_ELEM:
                        type = LFT_ICAP_REQ_HEADER;
                        break;
                    case LFT_ICAP_REP_HEADER_ELEM:
                        type = LFT_ICAP_REP_HEADER;
                        break;
#endif
                    default:
                        break;
                    }

                    break;

                case LFT_REQUEST_ALL_HEADERS:
                case LFT_ADAPTED_REQUEST_ALL_HEADERS:
                case LFT_REPLY_ALL_HEADERS:

#if ICAP_CLIENT
                case LFT_ICAP_LAST_MATCHED_ALL_HEADERS:
                case LFT_ICAP_REQ_ALL_HEADERS:
                case LFT_ICAP_REP_ALL_HEADERS:
#endif

                    switch (type) {
                    case LFT_REQUEST_ALL_HEADERS:
                        type = LFT_REQUEST_HEADER;
                        break;
                    case LFT_ADAPTED_REQUEST_ALL_HEADERS:
                        type = LFT_ADAPTED_REQUEST_HEADER;
                        break;
                    case LFT_REPLY_ALL_HEADERS:
                        type = LFT_REPLY_HEADER;
                        break;
#if ICAP_CLIENT
                    case LFT_ICAP_LAST_MATCHED_ALL_HEADERS:
                        type = LFT_ICAP_LAST_MATCHED_HEADER;
                        break;
                    case LFT_ICAP_REQ_ALL_HEADERS:
                        type = LFT_ICAP_REQ_HEADER;
                        break;
                    case LFT_ICAP_REP_ALL_HEADERS:
                        type = LFT_ICAP_REP_HEADER;
                        break;
#endif
                    default:
                        break;
                    }

                    break;

                default:
                    if (t->data.string)
                        arg = t->data.string;

                    break;
                }

                entry->append("%", 1);

                switch (t->quote) {

                case LOG_QUOTE_QUOTES:
                    entry->append("\"", 1);
                    break;

                case LOG_QUOTE_BRAKETS:
                    entry->append("[", 1);
                    break;

                case LOG_QUOTE_URL:
                    entry->append("#", 1);
                    break;

                case LOG_QUOTE_RAW:
                    entry->append("'", 1);
                    break;

                case LOG_QUOTE_NONE:
                    break;
                }

                if (t->left)
                    entry->append("-", 1);

                if (t->zero)
                    entry->append("0", 1);

                if (t->width)
                    storeAppendPrintf(entry, "%d", (int) t->width);

                if (t->precision)
                    storeAppendPrintf(entry, ".%d", (int) t->precision);

                if (arg)
                    storeAppendPrintf(entry, "{%s}", arg);

                for (te = logformat_token_table; te->config != NULL; te++) {
                    if (te->token_type == type) {
                        storeAppendPrintf(entry, "%s", te->config);
                        break;
                    }
                }

                if (t->space)
                    entry->append(" ", 1);

                assert(te->config != NULL);
            }
        }

        entry->append("\n", 1);
    }

}

void
accessLogFreeLogFormat(logformat_token ** tokens)
{
    while (*tokens) {
        logformat_token *token = *tokens;
        *tokens = token->next;
        safe_free(token->data.string);
        xfree(token);
    }
}

static void
accessLogSquid(AccessLogEntry * al, Logfile * logfile)
{
    const char *client = NULL;
    const char *user = NULL;
    char buf[MAX_IPSTRLEN];

    if (Config.onoff.log_fqdn) {
        client = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);
    }

    if (client == NULL) {
        client = al->cache.caddr.NtoA(buf,MAX_IPSTRLEN);
    }

    user = accessLogFormatName(al->cache.authuser);

    if (!user)
        user = accessLogFormatName(al->cache.extuser);

#if USE_SSL

    if (!user)
        user = accessLogFormatName(al->cache.ssluser);

#endif

    if (!user)
        user = accessLogFormatName(al->cache.rfc931);

    if (user && !*user)
        safe_free(user);

    if (!Config.onoff.log_mime_hdrs) {
        logfilePrintf(logfile, "%9ld.%03d %6d %s %s%s/%03d %"PRId64" %s %s %s %s%s/%s %s\n",
                      (long int) current_time.tv_sec,
                      (int) current_time.tv_usec / 1000,
                      al->cache.msec,
                      client,
                      log_tags[al->cache.code],
                      al->http.statusSfx(),
                      al->http.code,
                      al->cache.replySize,
                      al->_private.method_str,
                      al->url,
                      user ? user : dash_str,
                      al->hier.ping.timedout ? "TIMEOUT_" : "",
                      hier_code_str[al->hier.code],
                      al->hier.host,
                      al->http.content_type);
    } else {
        char *ereq = log_quote(al->headers.request);
        char *erep = log_quote(al->headers.reply);
        logfilePrintf(logfile, "%9ld.%03d %6d %s %s%s/%03d %"PRId64" %s %s %s %s%s/%s %s [%s] [%s]\n",
                      (long int) current_time.tv_sec,
                      (int) current_time.tv_usec / 1000,
                      al->cache.msec,
                      client,
                      log_tags[al->cache.code],
                      al->http.statusSfx(),
                      al->http.code,
                      al->cache.replySize,
                      al->_private.method_str,
                      al->url,
                      user ? user : dash_str,
                      al->hier.ping.timedout ? "TIMEOUT_" : "",
                      hier_code_str[al->hier.code],
                      al->hier.host,
                      al->http.content_type,
                      ereq,
                      erep);
        safe_free(ereq);
        safe_free(erep);
    }
    safe_free(user);
}

static void
accessLogCommon(AccessLogEntry * al, Logfile * logfile)
{
    const char *client = NULL;
    char *user1 = NULL, *user2 = NULL;
    char buf[MAX_IPSTRLEN];

    if (Config.onoff.log_fqdn) {
        client = fqdncache_gethostbyaddr(al->cache.caddr, 0);
    }

    if (client == NULL) {
        client = al->cache.caddr.NtoA(buf,MAX_IPSTRLEN);
    }

    user1 = accessLogFormatName(al->cache.authuser);

    user2 = accessLogFormatName(al->cache.rfc931);

    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s HTTP/%d.%d\" %d %"PRId64" %s%s:%s%s",
                  client,
                  user2 ? user2 : dash_str,
                  user1 ? user1 : dash_str,
                  mkhttpdlogtime(&squid_curtime),
                  al->_private.method_str,
                  al->url,
                  al->http.version.major, al->http.version.minor,
                  al->http.code,
                  al->cache.replySize,
                  log_tags[al->cache.code],
                  al->http.statusSfx(),
                  hier_code_str[al->hier.code],
                  (Config.onoff.log_mime_hdrs?"":"\n"));

    safe_free(user1);

    safe_free(user2);

    if (Config.onoff.log_mime_hdrs) {
        char *ereq = log_quote(al->headers.request);
        char *erep = log_quote(al->headers.reply);
        logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
        safe_free(ereq);
        safe_free(erep);
    }
}

#if ICAP_CLIENT
static void
accessLogICAPSquid(AccessLogEntry * al, Logfile * logfile)
{
    const char *client = NULL;
    const char *user = NULL;
    char tmp[MAX_IPSTRLEN], clientbuf[MAX_IPSTRLEN];

    if (al->cache.caddr.IsAnyAddr()) { // ICAP OPTIONS xactions lack client
        client = "-";
    } else {
        if (Config.onoff.log_fqdn)
            client = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);
        if (!client)
            client = al->cache.caddr.NtoA(clientbuf, MAX_IPSTRLEN);
    }

    user = accessLogFormatName(al->cache.authuser);

    if (!user)
        user = accessLogFormatName(al->cache.extuser);

#if USE_SSL

    if (!user)
        user = accessLogFormatName(al->cache.ssluser);

#endif

    if (!user)
        user = accessLogFormatName(al->cache.rfc931);

    if (user && !*user)
        safe_free(user);

    logfilePrintf(logfile, "%9ld.%03d %6d %s -/%03d %"PRId64" %s %s %s -/%s -\n",
                  (long int) current_time.tv_sec,
                  (int) current_time.tv_usec / 1000,

                  al->icap.trTime,
                  client,

                  al->icap.resStatus,
                  al->icap.bytesRead,
                  Adaptation::Icap::ICAP::methodStr(al->icap.reqMethod),
                  al->icap.reqUri.termedBuf(),
                  user ? user : dash_str,
                  al->icap.hostAddr.NtoA(tmp, MAX_IPSTRLEN));
    safe_free(user);
}
#endif

void
accessLogLogTo(customlog* log, AccessLogEntry * al, ACLChecklist * checklist)
