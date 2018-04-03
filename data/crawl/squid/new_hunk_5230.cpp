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
    /*LFT_CLIENT_PORT, */

    /*LFT_SERVER_IP_ADDRESS, */
    LFT_SERVER_IP_OR_PEER_NAME,
    /*LFT_SERVER_PORT, */

    LFT_LOCAL_IP,
    LFT_LOCAL_PORT,
    /*LFT_LOCAL_NAME, */

    LFT_TIME_SECONDS_SINCE_EPOCH,
    LFT_TIME_SUBSECOND,
    LFT_TIME_LOCALTIME,
    LFT_TIME_GMT,
    LFT_TIME_TO_HANDLE_REQUEST,

    LFT_REQUEST_HEADER,
    LFT_REQUEST_HEADER_ELEM,
    LFT_REQUEST_ALL_HEADERS,

    LFT_REPLY_HEADER,
    LFT_REPLY_HEADER_ELEM,
    LFT_REPLY_ALL_HEADERS,

    LFT_USER_NAME,
    LFT_USER_LOGIN,
    LFT_USER_IDENT,
    /*LFT_USER_REALM, */
    /*LFT_USER_SCHEME, */

    LFT_HTTP_CODE,
    /*LFT_HTTP_STATUS, */

    LFT_SQUID_STATUS,
    /*LFT_SQUID_ERROR, */
    LFT_SQUID_HIERARCHY,

    LFT_MIME_TYPE,

    LFT_REQUEST_METHOD,
    LFT_REQUEST_URI,
    /*LFT_REQUEST_QUERY, * // * this is not needed. see strip_query_terms */
    LFT_REQUEST_VERSION,

    /*LFT_REQUEST_SIZE_TOTAL, */
    /*LFT_REQUEST_SIZE_LINE, */
    /*LFT_REQUEST_SIZE_HEADERS, */
    /*LFT_REQUEST_SIZE_BODY, */
    /*LFT_REQUEST_SIZE_BODY_NO_TE, */

    LFT_REPLY_SIZE_TOTAL,
    /*LFT_REPLY_SIZE_LINE, */
    /*LFT_REPLY_SIZE_HEADERS, */
    /*LFT_REPLY_SIZE_BODY, */
    /*LFT_REPLY_SIZE_BODY_NO_TE, */

    LFT_PERCENT			/* special string cases for escaped chars */
} logformat_bcode_t;

enum log_quote {
    LOG_QUOTE_NONE = 0,
    LOG_QUOTE_QUOTES,
    LOG_QUOTE_BRAKETS,
    LOG_QUOTE_URL,
    LOG_QUOTE_RAW
};

struct _logformat_token
{
    logformat_bcode_t type;
    union {
        char *string;

        struct {
            char *header;
            char *element;
            char separator;
        }

        header;
        char *timespec;
    } data;
    unsigned char width;
    unsigned char precision;

enum log_quote quote:
    3;

unsigned int left:
    1;

unsigned int space:
    1;

unsigned int zero:
    1;
    int divisor;
    logformat_token *next;	/* todo: move from linked list to array */
};

struct logformat_token_table_entry
{
    const char *config;
    logformat_bcode_t token_type;
    int options;
};

struct logformat_token_table_entry logformat_token_table[] =
    {

        {">a", LFT_CLIENT_IP_ADDRESS},

        /*{ ">p", LFT_CLIENT_PORT}, */
        {">A", LFT_CLIENT_FQDN},

        /*{ "<a", LFT_SERVER_IP_ADDRESS }, */
        /*{ "<p", LFT_SERVER_PORT }, */
        {"<A", LFT_SERVER_IP_OR_PEER_NAME},

        {"la", LFT_LOCAL_IP},
        {"lp", LFT_LOCAL_PORT},
        /*{ "lA", LFT_LOCAL_NAME }, */

        {"ts", LFT_TIME_SECONDS_SINCE_EPOCH},
        {"tu", LFT_TIME_SUBSECOND},
        {"tl", LFT_TIME_LOCALTIME},
        {"tg", LFT_TIME_GMT},
        {"tr", LFT_TIME_TO_HANDLE_REQUEST},

        {">h", LFT_REQUEST_HEADER},
        {"<h", LFT_REPLY_HEADER},

        {"un", LFT_USER_NAME},
        {"ul", LFT_USER_LOGIN},
        /*{ "ur", LFT_USER_REALM }, */
        /*{ "us", LFT_USER_SCHEME }, */
        {"ui", LFT_USER_IDENT},

        {"Hs", LFT_HTTP_CODE},
        /*{ "Ht", LFT_HTTP_STATUS }, */

        {"Ss", LFT_SQUID_STATUS},
        /*{ "Se", LFT_SQUID_ERROR }, */
        {"Sh", LFT_SQUID_HIERARCHY},

        {"mt", LFT_MIME_TYPE},

        {"rm", LFT_REQUEST_METHOD},
        {"ru", LFT_REQUEST_URI},	/* doesn't include the query-string */
        /* { "rq", LFT_REQUEST_QUERY }, * /     / * the query-string, INCLUDING the leading ? */
        {">v", LFT_REQUEST_VERSION},
        {"rv", LFT_REQUEST_VERSION},

        /*{ ">st", LFT_REQUEST_SIZE_TOTAL }, */
        /*{ ">sl", LFT_REQUEST_SIZE_LINE }, * / / * the request line "GET ... " */
        /*{ ">sh", LFT_REQUEST_SIZE_HEADERS }, */
        /*{ ">sb", LFT_REQUEST_SIZE_BODY }, */
        /*{ ">sB", LFT_REQUEST_SIZE_BODY_NO_TE }, */

        {"<st", LFT_REPLY_SIZE_TOTAL},
        /*{ "<sl", LFT_REPLY_SIZE_LINE }, * /   / * the reply line (protocol, code, text) */
        /*{ "<sh", LFT_REPLY_SIZE_HEADERS }, */
        /*{ "<sb", LFT_REPLY_SIZE_BODY }, */
        /*{ "<sB", LFT_REPLY_SIZE_BODY_NO_TE }, */

        {"%", LFT_PERCENT},

        {NULL, LFT_NONE}		/* this must be last */
    };

static void
accessLogCustom(AccessLogEntry * al, customlog * log)
{
    logformat *lf;
    Logfile *logfile;
    logformat_token *fmt;
    static MemBuf mb = MemBufNULL;
    char tmp[1024];
    String sb;

    memBufReset(&mb);

    lf = log->logFormat;
    logfile = log->logfile;

    for (fmt = lf->format; fmt != NULL; fmt = fmt->next) {	/* for each token */
        const char *out = NULL;
        int quote = 0;
        long int outint = 0;
        int doint = 0;
        int dofree = 0;

        switch (fmt->type) {

        case LFT_NONE:
            out = "";
            break;

        case LFT_STRING:
            out = fmt->data.string;
            break;

        case LFT_CLIENT_IP_ADDRESS:
            out = inet_ntoa(al->cache.caddr);
            break;

        case LFT_CLIENT_FQDN:
            out = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);

            if (!out)
                out = inet_ntoa(al->cache.caddr);

            break;

            /* case LFT_CLIENT_PORT: */

            /* case LFT_SERVER_IP_ADDRESS: */

        case LFT_SERVER_IP_OR_PEER_NAME:
            out = al->hier.host;

            break;

            /* case LFT_SERVER_PORT: */

        case LFT_LOCAL_IP:
            if (al->request)
                out = inet_ntoa(al->request->my_addr);

            break;

        case LFT_LOCAL_PORT:
            if (al->request) {
                outint = al->request->my_port;
                doint = 1;
            }

            break;

        case LFT_TIME_SECONDS_SINCE_EPOCH:
            outint = current_time.tv_sec;
            doint = 1;
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

                if (!spec)
                    spec = "%d/%b/%Y %H:%M:%S";

                if (fmt->type == LFT_TIME_LOCALTIME)
                    t = localtime(&squid_curtime);
                else
                    t = gmtime(&squid_curtime);

                strftime(tmp, sizeof(tmp), spec, t);

                out = tmp;
            }

            break;

        case LFT_TIME_TO_HANDLE_REQUEST:
            outint = al->cache.msec;
            doint = 1;
            break;

        case LFT_REQUEST_HEADER:

            if (al->request)
                sb = httpHeaderGetByName(&al->request->header, fmt->data.header.header);

            out = sb.buf();

            quote = 1;

            break;

        case LFT_REPLY_HEADER:
            if (al->reply)
                sb = httpHeaderGetByName(&al->reply->header, fmt->data.header.header);

            out = sb.buf();

            quote = 1;

            break;

        case LFT_REQUEST_HEADER_ELEM:
            if (al->request)
                sb = httpHeaderGetByNameListMember(&al->request->header, fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);

            out = sb.buf();

            quote = 1;

            break;

        case LFT_REPLY_HEADER_ELEM:
            if (al->reply)
                sb = httpHeaderGetByNameListMember(&al->reply->header, fmt->data.header.header, fmt->data.header.element, fmt->data.header.separator);

            out = sb.buf();

            quote = 1;

            break;

        case LFT_REQUEST_ALL_HEADERS:
            out = al->headers.request;

            quote = 1;

            break;

        case LFT_REPLY_ALL_HEADERS:
            out = al->headers.reply;

            quote = 1;

            break;

        case LFT_USER_NAME:
            out = accessLogFormatName(al->cache.authuser ?
                                      al->cache.authuser : al->cache.rfc931);

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

            /* case LFT_USER_REALM: */
            /* case LFT_USER_SCHEME: */

        case LFT_HTTP_CODE:
            outint = al->http.code;

            doint = 1;

            break;

            /* case LFT_HTTP_STATUS:
             *           out = statusline->text;
             *     quote = 1;
             *     break;
             */

        case LFT_SQUID_STATUS:
            out = log_tags[al->cache.code];

            break;

            /* case LFT_SQUID_ERROR: */

        case LFT_SQUID_HIERARCHY:
            if (al->hier.ping.timedout)
                memBufAppend(&mb, "TIMEOUT_", 8);

            out = hier_strings[al->hier.code];

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

        case LFT_REQUEST_VERSION:
            snprintf(tmp, sizeof(tmp), "%d.%d", (int) al->http.version.major, (int) al->http.version.minor);

            out = tmp;

            break;

            /*case LFT_REQUEST_SIZE_TOTAL: */
            /*case LFT_REQUEST_SIZE_LINE: */
            /*case LFT_REQUEST_SIZE_HEADERS: */
            /*case LFT_REQUEST_SIZE_BODY: */
            /*case LFT_REQUEST_SIZE_BODY_NO_TE: */

        case LFT_REPLY_SIZE_TOTAL:
            outint = al->cache.size;

            doint = 1;

            break;

            /*case LFT_REPLY_SIZE_LINE: */
            /*case LFT_REPLY_SIZE_HEADERS: */
            /*case LFT_REPLY_SIZE_BODY: */
            /*case LFT_REPLY_SIZE_BODY_NO_TE: */

        case LFT_PERCENT:
            out = "%";

            break;
        }

        if (doint) {
            snprintf(tmp, sizeof(tmp), "%0*ld", fmt->zero ? (int) fmt->width : 0, outint);
            out = tmp;
        }

        if (out && *out) {
            if (quote) {
                char *newout = NULL;
                int newfree = 0;

                switch (fmt->quote) {

                case LOG_QUOTE_NONE:
                    newout = rfc1738_escape_unescaped(out);
                    newfree = 1;
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
                    memBufPrintf(&mb, "%-*s", (int) fmt->width, out);
                else
                    memBufPrintf(&mb, "%*s", (int) fmt->width, out);
            } else
                memBufAppend(&mb, out, strlen(out));
        } else {
            memBufAppend(&mb, "-", 1);
        }

        if (fmt->space)
            memBufAppend(&mb, " ", 1);

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
accessLogGetNewLogFormatToken(logformat_token * lt, char *def, char *last)
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
        *last = cur[l - 1];
        cur += l;
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
    }

    if (*cur == '-') {
        lt->left = 1;
        cur++;
    }

    if (*cur == '0') {
        lt->zero = 1;
        cur++;
    }

    if (isdigit(*cur))
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

    if (!lt->quote) {
        if (*last == '"' && *cur == '"')
            lt->quote = LOG_QUOTE_QUOTES;
        else if (*last == '[' && *cur == ']')
            lt->quote = LOG_QUOTE_BRAKETS;
    }

    if (*cur == ' ') {
        lt->space = 1;
        cur++;
    }

done:

    switch (lt->type) {

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

                lt->type = (lt->type == LFT_REQUEST_HEADER) ?
                           LFT_REQUEST_HEADER_ELEM :
                           LFT_REPLY_HEADER_ELEM;
            }

            lt->data.header.header = header;
        } else {
            lt->type = (lt->type == LFT_REQUEST_HEADER) ?
                       LFT_REQUEST_ALL_HEADERS :
                       LFT_REPLY_ALL_HEADERS;
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
    char last = '\0';

    debug(46, 1) ("accessLogParseLogFormat: got definition '%s'\n", def);

    /* very inefficent parser, but who cares, this needs to be simple */
    /* First off, let's tokenize, we'll optimize in a second pass.
     * A token can either be a %-prefixed sequence (usually a dynamic
     * token but it can be an escaped sequence), or a string. */
    cur = def;
    eos = def + strlen(def);
    *fmt = new_lt = last_lt = (logformat_token *)xmalloc(sizeof(logformat_token));
    cur += accessLogGetNewLogFormatToken(new_lt, cur, &last);

    while (cur < eos) {
        new_lt = (logformat_token *)xmalloc(sizeof(logformat_token));
        last_lt->next = new_lt;
        last_lt = new_lt;
        cur += accessLogGetNewLogFormatToken(new_lt, cur, &last);
    }

    return 1;
}

void
accessLogDumpLogFormat(StoreEntry * entry, const char *name, logformat * definitions)
{
    logformat_token *t;
    logformat *format;

    struct logformat_token_table_entry *te;
    debug(46, 0) ("accessLogDumpLogFormat called\n");

    for (format = definitions; format; format = format->next) {
        debug(46, 0) ("Dumping logformat definition for %s\n", format->name);
        storeAppendPrintf(entry, "logformat %s ", format->name);
        t = format->format;

        while (t != NULL) {
            if (t->type == LFT_STRING)
                storeAppendPrintf(entry, "%s", t->data.string);
            else {
                char arg[256];
                arg[0] = '\0';

                switch (t->type) {
                    /* special cases */

                case LFT_STRING:
                    break;

                case LFT_REQUEST_HEADER_ELEM:

                case LFT_REPLY_HEADER_ELEM:

                    if (t->data.header.separator != ',')
                        snprintf(arg, sizeof(arg), "%s:%c%s", t->data.header.header, t->data.header.separator, t->data.header.element);
                    else
                        snprintf(arg, sizeof(arg), "%s:%s", t->data.header.header, t->data.header.element);

                default:
                    if (t->data.string)
                        xstrncpy(arg, t->data.string, sizeof(arg));

                    break;
                }

                storeAppend(entry, "%", 1);

                switch (t->quote) {

                case LOG_QUOTE_QUOTES:
                    storeAppend(entry, "\"", 1);
                    break;

                case LOG_QUOTE_BRAKETS:
                    storeAppend(entry, "[", 1);
                    break;

                case LOG_QUOTE_URL:
                    storeAppend(entry, "#", 1);
                    break;

                case LOG_QUOTE_RAW:
                    storeAppend(entry, "'", 1);
                    break;

                case LOG_QUOTE_NONE:
                    break;
                }

                if (t->left)
                    storeAppend(entry, "-", 1);

                if (t->width)
                    storeAppendPrintf(entry, "%d", (int) t->width);

                if (t->precision)
                    storeAppendPrintf(entry, ".%d", (int) t->precision);

                if (*arg)
                    storeAppendPrintf(entry, "{%s}", arg);

                for (te = logformat_token_table; te->config != NULL; te++) {
                    if (te->token_type == t->type) {
                        storeAppendPrintf(entry, "%s", te->config);
                        break;
                    }
                }

                assert(te->config != NULL);
                break;
            }
        }
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
