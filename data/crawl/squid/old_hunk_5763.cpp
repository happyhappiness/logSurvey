 * "list" headers
 */
String
httpHeaderGetByName (const HttpHeader * hdr, const char *name)
{
  http_hdr_type id;
  HttpHeaderPos pos = HttpHeaderInitPos;
  HttpHeaderEntry *e;
  String result = StringNull;

  assert (hdr);
  assert (name);

  /* First try the quick path */
  id = httpHeaderIdByNameDef (name, strlen (name));
  if (id != -1)
    return httpHeaderGetStrOrList (hdr, id);

  /* Sorry, an unknown header name. Do linear search */
  while ((e = httpHeaderGetEntry (hdr, &pos)))
    {
      if (e->id == HDR_OTHER && strCaseCmp (e->name, name) == 0)
	{
	  strListAdd (&result, strBuf (e->value), ',');
	}
    }
  return result;
}

/* test if a field is present */
int
httpHeaderHas (const HttpHeader * hdr, http_hdr_type id)
{
  assert (hdr);
  assert_eid (id);
  assert (id != HDR_OTHER);
  debug (55, 7) ("%p lookup for %d\n", hdr, id);
  return CBIT_TEST (hdr->mask, id);
}

void
httpHeaderPutInt (HttpHeader * hdr, http_hdr_type id, int number)
{
  assert_eid (id);
  assert (Headers[id].type == ftInt);	/* must be of an appropriate type */
  assert (number >= 0);
  httpHeaderAddEntry (hdr, httpHeaderEntryCreate (id, NULL, xitoa (number)));
}

void
httpHeaderPutTime (HttpHeader * hdr, http_hdr_type id, time_t htime)
{
  assert_eid (id);
  assert (Headers[id].type == ftDate_1123);	/* must be of an appropriate type */
  assert (time >= 0);
  httpHeaderAddEntry (hdr, httpHeaderEntryCreate (id, NULL, mkrfc1123 (htime)));
}

void
httpHeaderPutStr (HttpHeader * hdr, http_hdr_type id, const char *str)
{
  assert_eid (id);
  assert (Headers[id].type == ftStr);	/* must be of an appropriate type */
  assert (str);
  httpHeaderAddEntry (hdr, httpHeaderEntryCreate (id, NULL, str));
}

void
httpHeaderPutAuth (HttpHeader * hdr, const char *auth_scheme, const char *realm)
{
  assert (hdr && auth_scheme && realm);
  httpHeaderPutStrf (hdr, HDR_WWW_AUTHENTICATE, "%s realm=\"%s\"", auth_scheme, realm);
}

void
httpHeaderPutCc (HttpHeader * hdr, const HttpHdrCc * cc)
{
  MemBuf mb;
  Packer p;
  assert (hdr && cc);
  /* remove old directives if any */
  httpHeaderDelById (hdr, HDR_CACHE_CONTROL);
  /* pack into mb */
  memBufDefInit (&mb);
  packerToMemInit (&p, &mb);
  httpHdrCcPackInto (cc, &p);
  /* put */
  httpHeaderAddEntry (hdr, httpHeaderEntryCreate (HDR_CACHE_CONTROL, NULL, mb.buf));
  /* cleanup */
  packerClean (&p);
  memBufClean (&mb);
}

void
httpHeaderPutContRange (HttpHeader * hdr, const HttpHdrContRange * cr)
{
  MemBuf mb;
  Packer p;
  assert (hdr && cr);
  /* remove old directives if any */
  httpHeaderDelById (hdr, HDR_CONTENT_RANGE);
  /* pack into mb */
  memBufDefInit (&mb);
  packerToMemInit (&p, &mb);
  httpHdrContRangePackInto (cr, &p);
  /* put */
  httpHeaderAddEntry (hdr, httpHeaderEntryCreate (HDR_CONTENT_RANGE, NULL, mb.buf));
  /* cleanup */
  packerClean (&p);
  memBufClean (&mb);
}

void
httpHeaderPutRange (HttpHeader * hdr, const HttpHdrRange * range)
{
  MemBuf mb;
  Packer p;
  assert (hdr && range);
  /* remove old directives if any */
  httpHeaderDelById (hdr, HDR_RANGE);
  /* pack into mb */
  memBufDefInit (&mb);
  packerToMemInit (&p, &mb);
  httpHdrRangePackInto (range, &p);
  /* put */
  httpHeaderAddEntry (hdr, httpHeaderEntryCreate (HDR_RANGE, NULL, mb.buf));
  /* cleanup */
  packerClean (&p);
  memBufClean (&mb);
}

/* add extension header (these fields are not parsed/analyzed/joined, etc.) */
void
httpHeaderPutExt (HttpHeader * hdr, const char *name, const char *value)
{
  assert (name && value);
  debug (55, 8) ("%p adds ext entry '%s: %s'\n", hdr, name, value);
  httpHeaderAddEntry (hdr, httpHeaderEntryCreate (HDR_OTHER, name, value));
}

int
httpHeaderGetInt (const HttpHeader * hdr, http_hdr_type id)
{
  HttpHeaderEntry *e;
  int value = -1;
  int ok;
  assert_eid (id);
  assert (Headers[id].type == ftInt);	/* must be of an appropriate type */
  if ((e = httpHeaderFindEntry (hdr, id)))
    {
      ok = httpHeaderParseInt (strBuf (e->value), &value);
      httpHeaderNoteParsedEntry (e->id, e->value, !ok);
    }
  return value;
}

time_t
httpHeaderGetTime (const HttpHeader * hdr, http_hdr_type id)
{
  HttpHeaderEntry *e;
  time_t value = -1;
  assert_eid (id);
  assert (Headers[id].type == ftDate_1123);	/* must be of an appropriate type */
  if ((e = httpHeaderFindEntry (hdr, id)))
    {
      value = parse_rfc1123 (strBuf (e->value));
      httpHeaderNoteParsedEntry (e->id, e->value, value < 0);
    }
  return value;
}

/* sync with httpHeaderGetLastStr */
const char *
httpHeaderGetStr (const HttpHeader * hdr, http_hdr_type id)
{
  HttpHeaderEntry *e;
  assert_eid (id);
  assert (Headers[id].type == ftStr);	/* must be of an appropriate type */
  if ((e = httpHeaderFindEntry (hdr, id)))
    {
      httpHeaderNoteParsedEntry (e->id, e->value, 0);	/* no errors are possible */
      return strBuf (e->value);
    }
  return NULL;
}

/* unusual */
const char *
httpHeaderGetLastStr (const HttpHeader * hdr, http_hdr_type id)
{
  HttpHeaderEntry *e;
  assert_eid (id);
  assert (Headers[id].type == ftStr);	/* must be of an appropriate type */
  if ((e = httpHeaderFindLastEntry (hdr, id)))
    {
      httpHeaderNoteParsedEntry (e->id, e->value, 0);	/* no errors are possible */
      return strBuf (e->value);
    }
  return NULL;
}

HttpHdrCc *
httpHeaderGetCc (const HttpHeader * hdr)
{
  HttpHdrCc *cc;
  String s;
  if (!CBIT_TEST (hdr->mask, HDR_CACHE_CONTROL))
    return NULL;
  s = httpHeaderGetList (hdr, HDR_CACHE_CONTROL);
  cc = httpHdrCcParseCreate (&s);
  HttpHeaderStats[hdr->owner].ccParsedCount++;
  if (cc)
    httpHdrCcUpdateStats (cc, &HttpHeaderStats[hdr->owner].ccTypeDistr);
  httpHeaderNoteParsedEntry (HDR_CACHE_CONTROL, s, !cc);
  stringClean (&s);
  return cc;
}

HttpHdrRange *
httpHeaderGetRange (const HttpHeader * hdr)
{
  HttpHdrRange *r = NULL;
  HttpHeaderEntry *e;
  /* some clients will send "Request-Range" _and_ *matching* "Range"
   * who knows, some clients might send Request-Range only;
   * this "if" should work correctly in both cases;
   * hopefully no clients send mismatched headers! */
  if ((e = httpHeaderFindEntry (hdr, HDR_RANGE)) ||
      (e = httpHeaderFindEntry (hdr, HDR_REQUEST_RANGE)))
    {
      r = httpHdrRangeParseCreate (&e->value);
      httpHeaderNoteParsedEntry (e->id, e->value, !r);
    }
  return r;
}

HttpHdrContRange *
httpHeaderGetContRange (const HttpHeader * hdr)
{
  HttpHdrContRange *cr = NULL;
  HttpHeaderEntry *e;
  if ((e = httpHeaderFindEntry (hdr, HDR_CONTENT_RANGE)))
    {
      cr = httpHdrContRangeParseCreate (strBuf (e->value));
      httpHeaderNoteParsedEntry (e->id, e->value, !cr);
    }
  return cr;
}

const char *
httpHeaderGetAuth (const HttpHeader * hdr, http_hdr_type id, const char *auth_scheme)
{
  const char *field;
  int l;
  assert (hdr && auth_scheme);
  field = httpHeaderGetStr (hdr, id);
  if (!field)			/* no authorization field */
    return NULL;
  l = strlen (auth_scheme);
  if (!l || strncasecmp (field, auth_scheme, l))	/* wrong scheme */
    return NULL;
  field += l;
  if (!xisspace (*field))	/* wrong scheme */
    return NULL;
  /* skip white space */
  field += xcountws (field);
  if (!*field)			/* no authorization cookie */
    return NULL;
  return base64_decode (field);
}

ETag
httpHeaderGetETag (const HttpHeader * hdr, http_hdr_type id)
{
  ETag etag =
  {NULL, -1};
  HttpHeaderEntry *e;
  assert (Headers[id].type == ftETag);	/* must be of an appropriate type */
  if ((e = httpHeaderFindEntry (hdr, id)))
    etagParseInit (&etag, strBuf (e->value));
  return etag;
}

TimeOrTag
httpHeaderGetTimeOrTag (const HttpHeader * hdr, http_hdr_type id)
{
  TimeOrTag tot;
  HttpHeaderEntry *e;
  assert (Headers[id].type == ftDate_1123_or_ETag);	/* must be of an appropriate type */
  memset (&tot, 0, sizeof (tot));
  if ((e = httpHeaderFindEntry (hdr, id)))
    {
      const char *str = strBuf (e->value);
      /* try as an ETag */
      if (etagParseInit (&tot.tag, str))
	{
	  tot.valid = tot.tag.str != NULL;
	  tot.time = -1;
	}
      else
	{
	  /* or maybe it is time? */
	  tot.time = parse_rfc1123 (str);
	  tot.valid = tot.time >= 0;
	  tot.tag.str = NULL;
	}
    }
  assert (tot.time < 0 || !tot.tag.str);	/* paranoid */
  return tot;
}

/*
 * HttpHeaderEntry
 */

static HttpHeaderEntry *
httpHeaderEntryCreate (http_hdr_type id, const char *name, const char *value)
{
  HttpHeaderEntry *e;
  assert_eid (id);
  e = memAllocate (MEM_HTTP_HDR_ENTRY);
  e->id = id;
  if (id != HDR_OTHER)
    e->name = Headers[id].name;
  else
    stringInit (&e->name, name);
  stringInit (&e->value, value);
  Headers[id].stat.aliveCount++;
  debug (55, 9) ("created entry %p: '%s: %s'\n", e, strBuf (e->name), strBuf (e->value));
  return e;
}

static void
httpHeaderEntryDestroy (HttpHeaderEntry * e)
{
  assert (e);
  assert_eid (e->id);
  debug (55, 9) ("destroying entry %p: '%s: %s'\n", e, strBuf (e->name), strBuf (e->value));
  /* clean name if needed */
  if (e->id == HDR_OTHER)
    stringClean (&e->name);
  stringClean (&e->value);
  assert (Headers[e->id].stat.aliveCount);
  Headers[e->id].stat.aliveCount--;
  e->id = -1;
  memFree (e, MEM_HTTP_HDR_ENTRY);
}

/* parses and inits header entry, returns new entry on success */
static HttpHeaderEntry *
httpHeaderEntryParseCreate (const char *field_start, const char *field_end)
{
  HttpHeaderEntry *e;
  int id;
  /* note: name_start == field_start */
  const char *name_end = strchr (field_start, ':');
  const int name_len = name_end ? name_end - field_start : 0;
  const char *value_start = field_start + name_len + 1;		/* skip ':' */
  /* note: value_end == field_end */

  HeaderEntryParsedCount++;

  /* do we have a valid field name within this field? */
  if (!name_len || name_end > field_end)
    return NULL;
  if (name_len > 65536)
    {
      /* String has a 64K limit */
      debug (55, 1) ("WARNING: ignoring header name of %d bytes\n", name_len);
      return NULL;
    }
  /* now we know we can parse it */
  e = memAllocate (MEM_HTTP_HDR_ENTRY);
  debug (55, 9) ("creating entry %p: near '%s'\n", e, getStringPrefix (field_start, field_end));
  /* is it a "known" field? */
  id = httpHeaderIdByName (field_start, name_len, Headers, HDR_ENUM_END);
  if (id < 0)
    id = HDR_OTHER;
  assert_eid (id);
  e->id = id;
  /* set field name */
  if (id == HDR_OTHER)
    stringLimitInit (&e->name, field_start, name_len);
  else
    e->name = Headers[id].name;
  /* trim field value */
  while (value_start < field_end && xisspace (*value_start))
    value_start++;
  if (field_end - value_start > 65536)
    {
      /* String has a 64K limit */
      debug (55, 1) ("WARNING: ignoring '%s' header of %d bytes\n",
		     strBuf (e->name), field_end - value_start);
      if (e->id == HDR_OTHER)
	stringClean (&e->name);
      memFree (e, MEM_HTTP_HDR_ENTRY);
      return NULL;
    }
  /* set field value */
  stringLimitInit (&e->value, value_start, field_end - value_start);
  Headers[id].stat.seenCount++;
  Headers[id].stat.aliveCount++;
  debug (55, 9) ("created entry %p: '%s: %s'\n", e, strBuf (e->name), strBuf (e->value));
  return e;
}

HttpHeaderEntry *
httpHeaderEntryClone (const HttpHeaderEntry * e)
{
  return httpHeaderEntryCreate (e->id, strBuf (e->name), strBuf (e->value));
}

void
httpHeaderEntryPackInto (const HttpHeaderEntry * e, Packer * p)
{
  assert (e && p);
  packerAppend (p, strBuf (e->name), strLen (e->name));
  packerAppend (p, ": ", 2);
  packerAppend (p, strBuf (e->value), strLen (e->value));
  packerAppend (p, "\r\n", 2);
}

static void
httpHeaderNoteParsedEntry (http_hdr_type id, String context, int error)
{
  Headers[id].stat.parsCount++;
  if (error)
    {
      Headers[id].stat.errCount++;
      debug (55, 2) ("cannot parse hdr field: '%s: %s'\n",
		     strBuf (Headers[id].name), strBuf (context));
    }
}

