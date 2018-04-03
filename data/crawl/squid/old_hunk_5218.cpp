#endif

void
esiVar::deleteSelf() const
{
    delete this;
}

/* esiVarState */
void
esiVarStateFree (void *data)
{
    esiVarState *thisNode = (esiVarState*)data;
    thisNode->freeResources();
}

void
esiVarState::freeResources()
{
    input = NULL;
    ESISegmentFreeList (output);
    httpHeaderClean (&hdr);

    if (query) {
        unsigned int i;

        for (i = 0; i < query_elements; ++i) {
            safe_free(query[i].var);
            safe_free(query[i].val);
        }

        memFreeBuf (query_sz, query);
    }

    safe_free (query_string);
    safe_free (browserversion);
}

void *
esiVarState::operator new(size_t byteCount)
{
    assert (byteCount == sizeof (esiVarState));
    void *rv;
    CBDATA_INIT_TYPE_FREECB(esiVarState, esiVarStateFree);
    rv = (void *)cbdataAlloc (esiVarState);
    return rv;
}

void
esiVarState::operator delete (void *address)
{
    cbdataFree (address);
}

void
esiVarState::deleteSelf() const
{
    delete this;
}

char *
esiVarState::getProductVersion (char const *s)
{
    char const *t;
    int len;
    t = index (s,'/');

    if (!t || !*(++t))
        return xstrdup ("");

    len = strcspn (t, " \r\n()<>@,;:\\\"/[]?={}");

    return xstrndup (t, len);
}

esiVarState::esiVarState (HttpHeader const *aHeader, char const *uri)
        : output (NULL)
{
    /* Fill out variable values */
    /* Count off the query elements */
    char const *query_start = strchr (uri, '?');

    if (query_start && query_start[1] != '\0' ) {
        unsigned int n;
        query_string = xstrdup (query_start + 1);
        query_elements = 1;
        char const *query_pos = query_start + 1;

        while ((query_pos = strchr (query_pos, '&'))) {
            ++query_elements;
            ++query_pos;
        }

        query = (_query_elem *)memReallocBuf(query, query_elements * sizeof (struct _query_elem),
                                             &query_sz);
        query_pos = query_start + 1;
        n = 0;

        while (query_pos) {
            char *next = strchr (query_pos, '&');
            char *div = strchr (query_pos, '=');

            if (next)
                ++next;

            assert (n < query_elements);

            if (!div)
                div = next;

            if (!(div - query_pos + 1))
                /* zero length between & and = or & and & */
                continue;

            query[n].var = xstrndup (query_pos, div - query_pos + 1) ;

            if (div == next) {
                query[n].val = xstrdup ("");
            } else {
                query[n].val = xstrndup (div + 1, next - div - 1);
            }

            query_pos = next;
            ++n;
        }
    } else {
        query_string = xstrdup ("");
    }

    if (query) {
        unsigned int n = 0;
        debug (86,6)("esiVarStateNew: Parsed Query string: '%s'\n",uri);

        while (n < query_elements) {
            debug (86,6)("esiVarStateNew: Parsed Query element %d '%s'='%s'\n",n + 1, query[n].var, query[n].val);
            ++n;
        }
    }

    /* Now setup the UserAgent values */
    /* An example:
     *    User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; .NET CLR 1.0.3705) */
    /* Grr thisNode is painful - RFC 2616 specifies that 'by convention' the tokens are in order of importance
     * in identifying the product. According to the RFC the above should be interpreted as:
     * Product - Mozilla version 4.0
     * in comments - compatible; .... 3705 
     *
     * Useing the RFC a more appropriate header would be
     *    User-Agent: MSIE/6.0 Mozilla/4.0 Windows-NT/5.1 .NET-CLR/1.0.3705
     *    or something similar.
     *
     * Because we can't parse under those rules and get real-world useful answers, we follow the following 
     * algorithm:
     * if the string Windows appears in the header, the OS is WIN.
     * If the string Mac appears in the header, the OS is MAC.
     * If the string nix, or BSD appears in the header, the OS is UNIX.
     * If the string MSIE appears in the header, the BROWSER is MSIE, and the version is the string from 
     * MSIE<sp> to the first ;, or end of string.
     * If the String MSIE does not appear in the header, and MOZILLA does, we use the version from the 
     * /version field.
     * if MOZILLA doesn't appear, the browser is set to OTHER.
     * In future, thisNode may be better implemented as a regexp.
     */
    /* TODO: only grab the needed headers */
    httpHeaderInit (&hdr, hoReply);

    httpHeaderAppend (&hdr, aHeader);

    if (httpHeaderHas(&hdr, HDR_USER_AGENT)) {
        char const *s = httpHeaderGetStr (&hdr, HDR_USER_AGENT);
        char const *t, *t1;

        if (strstr (s, "Windows"))
            UserOs = ESI_OS_WIN;
        else if (strstr (s, "Mac"))
            UserOs = ESI_OS_MAC;
        else if (strstr (s, "nix") || strstr (s, "BSD"))
            UserOs = ESI_OS_UNIX;
        else
            UserOs = ESI_OS_OTHER;

        /* Now the browser and version */
        if ((t = strstr (s, "MSIE"))) {
            browser = ESI_BROWSER_MSIE;
            t = index (t, ' ');

            if (!t)
                browserversion = xstrdup ("");
            else {
                t1 = index (t, ';');

                if (!t1)
                    browserversion = xstrdup (t + 1);
                else
                    browserversion = xstrndup (t + 1, t1-t);
            }
        } else if (strstr (s, "Mozilla")) {
            browser = ESI_BROWSER_MOZILLA;
            browserversion = getProductVersion(s);
        } else {
            browser = ESI_BROWSER_OTHER;
            browserversion = getProductVersion(s);
        }
    } else {
        UserOs = ESI_OS_OTHER;
        browser = ESI_BROWSER_OTHER;
        browserversion = xstrdup ("");
    }
}

void
esiVarState::feedData (const char *buf, size_t len)
{
    /* TODO: if needed - tune to skip segment iteration */
    debug (86,6)("esiVarState::feedData: accepting %d bytes\n", len);
    ESISegment::ListAppend (input, buf, len);
}

ESISegment::Pointer
esiVarState::extractList()
{
    doIt();
    ESISegment::Pointer rv = output;
    output = NULL;
    debug (86,6)("esiVarStateExtractList: Extracted list\n");
    return rv;
}

char *
esiVarState::extractChar ()
{
    if (!input.getRaw())
        fatal ("Attempt to extract variable state with no data fed in \n");

    doIt();

    char *rv = output->listToChar();

    ESISegmentFreeList (output);

    debug (86,6)("esiVarStateExtractList: Extracted char\n");

    return rv;
}

int
httpHeaderHasListMember(const HttpHeader * hdr, http_hdr_type id, const char *member, const char separator);

int
httpHeaderHasListMember(const HttpHeader * hdr, http_hdr_type id, const char *member, const char separator)
{
    int result = 0;
    const char *pos = NULL;
    const char *item;
    int ilen;
    int mlen = strlen(member);

    assert(hdr);
    assert(id >= 0);

    String header (httpHeaderGetStrOrList(hdr, id));

    while (strListGetItem(&header, separator, &item, &ilen, &pos)) {
        if (strncmp(item, member, mlen) == 0
                && (item[mlen] == '=' || item[mlen] == separator || item[mlen] == ';' || item[mlen] == '\0')) {
            result = 1;
            break;
        }
    }

    return result;
}

void
esiVarState::eval (esiVar_t type, char const *subref, char const *found_default )
{
    const char *s = NULL;

    if (!found_default)
        found_default = "";

    switch (type) {

    case ESI_VAR_HOST:
        flags.host = 1;

        if (!subref && httpHeaderHas(&hdr,HDR_HOST)) {
            s = httpHeaderGetStr (&hdr, HDR_HOST);
        } else
            s = found_default;

        ESISegment::ListAppend (output, s, strlen (s));

        break;

    case ESI_VAR_COOKIE:
        flags.cookie = 1;

        if (httpHeaderHas(&hdr, HDR_COOKIE)) {
            if (!subref)
                s = httpHeaderGetStr (&hdr, HDR_COOKIE);
            else {
                String S = httpHeaderGetListMember (&hdr, HDR_COOKIE, subref, ';');

                if (S.size())
                    ESISegment::ListAppend (output, S.buf(), S.size());
                else if (found_default)
                    ESISegment::ListAppend (output, found_default, strlen (found_default));
            }
        } else
            s = found_default;

        if (s)
            ESISegment::ListAppend (output, s, strlen (s));

        break;

    case ESI_VAR_REFERER:
        flags.referer = 1;

        if (!subref && httpHeaderHas(&hdr, HDR_REFERER))
            s = httpHeaderGetStr (&hdr, HDR_REFERER);
        else
            s = found_default;

        ESISegment::ListAppend (output, s, strlen (s));

        break;

    case ESI_QUERY_STRING:
        if (!subref)
            s = query_string;
        else {
            unsigned int i = 0;

            while (i < query_elements && !s) {
                if (!strcmp (subref, query[i].var))
                    s = query[i].val;

                ++i;
            }

            if (!s)
                s = found_default;
        }

        ESISegment::ListAppend (output, s, strlen (s));
        break;

    case ESI_VAR_USERAGENT:
        flags.useragent = 1;

        if (httpHeaderHas(&hdr, HDR_USER_AGENT)) {
            if (!subref)
                s = httpHeaderGetStr (&hdr, HDR_USER_AGENT);
            else {
                if (!strcmp (subref, "os")) {
                    s = esiUserOs[UserOs];
                } else if (!strcmp (subref, "browser")) {
                    s = esiBrowsers[browser];
                } else if (!strcmp (subref, "version")) {
                    s = browserversion;
                } else
                    s = "";
            }
        } else
            s = found_default;

        ESISegment::ListAppend (output, s, strlen (s));

        break;

    case ESI_VAR_LANGUAGE:
        flags.language = 1;

        if (httpHeaderHas(&hdr, HDR_ACCEPT_LANGUAGE)) {
            if (!subref) {
                String S (httpHeaderGetList (&hdr, HDR_ACCEPT_LANGUAGE));
                ESISegment::ListAppend (output, S.buf(), S.size());
            } else {
                if (httpHeaderHasListMember (&hdr, HDR_ACCEPT_LANGUAGE, subref, ',')) {
                    s = "true";
                } else {
                    s = "false";
                }

                ESISegment::ListAppend (output, s, strlen (s));
            }
        } else {
            s = found_default;
            ESISegment::ListAppend (output, s, strlen (s));
        }

        break;

    case ESI_VAR_OTHER:
        /* No-op. We swallow it */

        if (found_default) {
            ESISegment::ListAppend (output, found_default, strlen (found_default));
        }

        break;
    }
}

bool
esiVarState::validChar (char c)
{
    if (('A' <= c && c <= 'Z') ||
            ('a' <= c && c <= 'z') ||
            '_' == c || '-' == c)
        return true;

    return false;
}

esiVarState::esiVar_t
esiVarState::GetVar(char *s, int len)
{
    assert (s);

    if (len == 9) {
        if (!strncmp (s, "HTTP_HOST", 9))
            return ESI_VAR_HOST;
        else
            return ESI_VAR_OTHER;
    }

    if (len == 11) {
        if (!strncmp (s, "HTTP_COOKIE", 11))
            return ESI_VAR_COOKIE;
        else
            return ESI_VAR_OTHER;
    }

    if (len == 12) {
        if (!strncmp (s, "HTTP_REFERER", 12))
            return ESI_VAR_REFERER;
        else if (!strncmp (s, "QUERY_STRING", 12))
            return ESI_QUERY_STRING;
        else
            return ESI_VAR_OTHER;
    }

    if (len == 15) {
        if (!strncmp (s, "HTTP_USER_AGENT", 15))
            return ESI_VAR_USERAGENT;
        else
            return ESI_VAR_OTHER;
    }

    if (len == 20) {
        if (!strncmp (s, "HTTP_ACCEPT_LANGUAGE", 20))
            return ESI_VAR_LANGUAGE;
        else
            return ESI_VAR_OTHER;
    }

    return ESI_VAR_OTHER;
}

/* because we are only used to process:
 * - include URL's
 * - non-esi elements
 * - choose clauses
 * buffering is ok - we won't delay the start of async activity, or
 * of output data preparation
 */
void
esiVarState::doIt ()
{
    assert (output == NULL);
    int state = 0;
    char *string = input->listToChar();
    size_t len = strlen (string);
    size_t pos = 0;
    size_t var_pos = 0;
    size_t done_pos = 0;
    char * found_subref = NULL;
    char *found_default = NULL;
    esiVar_t vartype = ESI_VAR_OTHER;
    ESISegmentFreeList (input);

    while (pos < len) {
        switch (state) {

        case 0: /* skipping pre-variables */

            if (string[pos] != '$') {
                ++pos;
            } else {
                if (pos - done_pos)
                    /* extract known good text */
                    ESISegment::ListAppend (output, string + done_pos, pos - done_pos);

                done_pos = pos;

                state = 1;

                ++pos;
            }

            break;

        case 1:/* looking for ( */

            if (string[pos] != '(') {
                state = 0;
            } else {
                state = 2; /* extract a variable name */
                var_pos = ++pos;
            }

            break;

        case 2: /* looking for variable name */

            if (!validChar(string[pos])) {
                /* not a variable name char */

                if (pos - var_pos)
                    vartype = GetVar (string + var_pos, pos - var_pos);

                state = 3;
            } else {
                ++pos;
            }

            break;

        case 3: /* looking for variable subref, end bracket or default indicator */

            if (string[pos] == ')') {
                /* end of string */
                eval(vartype, found_subref, found_default);
                done_pos = ++pos;
                safe_free(found_subref);
                safe_free(found_default);
                state = 0;
            } else if (!found_subref && !found_default && string[pos] == '{') {
                debug (86,6)("esiVarStateDoIt: Subref of some sort\n");
                /* subreference of some sort */
                /* look for the entry name */
                var_pos = ++pos;
                state = 4;
            } else if (!found_default && string[pos] == '|') {
                debug (86,6)("esiVarStateDoIt: Default present\n");
                /* extract default value */
                state = 5;
                var_pos = ++pos;
            } else {
                /* unexpected char, not a variable after all */
                debug (86,6)("esiVarStateDoIt: unexpected char after varname\n");
                state = 0;
                pos = done_pos + 2;
            }

            break;

        case 4: /* looking for variable subref */

            if (string[pos] == '}') {
                /* end of subref */
                found_subref = xstrndup (&string[var_pos], pos - var_pos + 1);
                debug (86,6)("esiVarStateDoIt: found end of variable subref '%s'\n", found_subref);
                state = 3;
                ++pos;
            } else if (!validChar (string[pos])) {
                debug (86,6)("esiVarStateDoIt: found invalid char in variable subref\n");
                /* not a valid subref */
                safe_free(found_subref);
                state = 0;
                pos = done_pos + 2;
            } else {
                ++pos;
            }

            break;

        case 5: /* looking for a default value */

            if (string[pos] == '\'') {
                /* begins with a quote */
                debug (86,6)("esiVarStateDoIt: found quoted default\n");
                state = 6;
                var_pos = ++pos;
            } else {
                /* doesn't */
                debug (86,6)("esiVarStateDoIt: found unquoted default\n");
                state = 7;
                ++pos;
            }

            break;

        case 6: /* looking for a quote terminate default value */

            if (string[pos] == '\'') {
                /* end of default */
                found_default = xstrndup (&string[var_pos], pos - var_pos + 1);
                debug (86,6)("esiVarStateDoIt: found end of quoted default '%s'\n", found_default);
                state = 3;
            }

            ++pos;
            break;

        case 7: /* looking for } terminate default value */

            if (string[pos] == ')') {
                /* end of default - end of variable*/
                found_default = xstrndup (&string[var_pos], pos - var_pos + 1);
                debug (86,6)("esiVarStateDoIt: found end of variable (w/ unquoted default) '%s'\n",found_default);
                eval(vartype,found_subref, found_default);
                done_pos = ++pos;
                safe_free(found_default);
                safe_free(found_subref);
                state = 0;
            }

            ++pos;
            break;

        default:
            fatal("esiVarStateDoIt: unexpected state\n");
        }
    }

    /* pos-done_pos chars are ready to copy */
    if (pos-done_pos)
        ESISegment::ListAppend (output, string+done_pos, pos - done_pos);

    safe_free (found_default);

    safe_free (found_subref);
}

/* XXX FIXME: this should be comma delimited, no? */
void
esiVarState::buildVary (HttpReply *rep)
{
    char tempstr[1024];
    tempstr[0]='\0';

    if (flags.language)
        strcat (tempstr, "Accept-Language ");

    if (flags.cookie)
        strcat (tempstr, "Cookie ");

    if (flags.host)
        strcat (tempstr, "Host ");

    if (flags.referer)
        strcat (tempstr, "Referer ");

    if (flags.useragent)
        strcat (tempstr, "User-Agent ");

    if (!tempstr[0])
        return;

    String strVary (httpHeaderGetList (&rep->header, HDR_VARY));

    if (!strVary.size() || strVary.buf()[0] != '*') {
        httpHeaderPutStr (&rep->header, HDR_VARY, tempstr);
    }
}

/* esiChoose */
esiChoose::~esiChoose()
{
