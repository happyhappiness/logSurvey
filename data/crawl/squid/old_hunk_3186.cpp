static bool no_fork  = false;
static const char* programname = 0;
static const char* RCS_ID =
"$Id: purge.cc,v 1.17 2000/09/21 10:59:53 cached Exp $";

// ----------------------------------------------------------------------

struct REList {
  REList( const char* what, bool doCase );
  ~REList();
  bool match( const char* check ) const;

  REList*     next;
  const char* data;
  regex_t     rexp;
};

REList::REList( const char* what, bool doCase )
  :next(0),data(strdup(what))
{
  int result = regcomp( &rexp, what, 
			REG_EXTENDED | REG_NOSUB | (doCase ? 0 : REG_ICASE) );
  if ( result != 0 ) {
    char buffer[256];
    regerror( result, &rexp, buffer, 256 );
    fprintf( stderr, "unable to compile re \"%s\": %s\n", what, buffer );
    exit(1);
  }
}

REList::~REList()
{ 
  if ( next ) delete next;
  if ( data ) free((void*) data);
  regfree(&rexp);
}

bool
REList::match( const char* check ) const
{
  int result = regexec( &rexp, check, 0, 0, 0 );
  if ( result != 0 && result != REG_NOMATCH ) {
    char buffer[256];
    regerror( result, &rexp, buffer, 256 );
    fprintf( stderr, "unable to execute re \"%s\"\n+ on line \"%s\": %s\n",
	     data, check, buffer );
    exit(1);
  }
  return ( result == 0 );
}

// ----------------------------------------------------------------------

char*
concat( const char* start, ... )
  // purpose: concatinate an arbitrary number of C strings.
  // paramtr: start (IN): first C string
  //          ... (IN): further C strings, terminated with a NULL pointer
  // returns: memory allocated via new(), containing the concatinated string.
{
  va_list ap;
  const char* s;

  // first run: determine size
  unsigned size = strlen(start)+1;
  va_start( ap, start );
  while ( (s=va_arg(ap,const char*)) != NULL ) size += strlen(s ? s : "");
  va_end(ap);

  // allocate
  char* result = new char[size];
  if ( result == 0 ) {
    perror( "string memory allocation" );
    exit(1);
  }

  // second run: copy content
  strcpy( result, start );
  va_start( ap, start );
  while ( (s=va_arg(ap,const char*)) != NULL ) strcat( result, s );
  va_end(ap);

  return result;
}

bool
isxstring( const char* s, size_t testlen )
  // purpose: test a string for conforming to xdigit
  // paramtr: s (IN): string to test
  //          testlen (IN): length the string must have
  // returns: true, iff strlen(s)==testlen && all_x_chars(s), false otherwise
{
  if ( strlen(s) != testlen ) return false;

  size_t i=0;
  while ( i<testlen && isxdigit(s[i]) ) i++;
  return (i==testlen);
}

inline
int
log_output( const char* fn, int code, long size, const char* url )
{
  return printf( "%s %3d %8ld %s\n", fn, code, size, url );
}

static
int
log_extended( const char* fn, int code, long size, const SquidMetaList* meta )
{
  static const char hexdigit[] = "0123456789ABCDEF";
  char md5[34];
  const SquidTLV* findings = 0;

  if ( meta && (findings = meta->search( STORE_META_KEY_MD5 )) ) {
    unsigned char* s = (unsigned char*) findings->data;
    for ( int j=0; j<16; j++, s++ ) {
      md5[j*2+0] = hexdigit[ *s >> 4 ];
      md5[j*2+1] = hexdigit[ *s & 15 ];
    }
    md5[32] = '\0'; // terminate string
  } else {
    sprintf( md5, "%-32s", "(no_md5_data_available)" );
  }

  char timeb[64];
  if ( meta && (findings = meta->search( STORE_META_STD )) ) {
    StoreMetaStd temp;
    // make data aligned, avoid SIGBUS on RISC machines (ARGH!)
    memcpy( &temp, findings->data, sizeof(StoreMetaStd) );
    sprintf( timeb, "%08x %08x %08x %08x %04x %5hu ",
	     temp.timestamp, temp.lastref,
	     temp.expires, temp.lastmod, temp.flags, temp.refcount );
  } else if ( meta && (findings = meta->search( STORE_META_STD_LFS )) ) {
    StoreMetaStdLFS temp;
    // make data aligned, avoid SIGBUS on RISC machines (ARGH!)
    memcpy( &temp, findings->data, sizeof(StoreMetaStd) );
    sprintf( timeb, "%08x %08x %08x %08x %04x %5hu ",
	     temp.timestamp, temp.lastref,
	     temp.expires, temp.lastmod, temp.flags, temp.refcount );
  } else {
    sprintf( timeb, "%08x %08x %08x %08x %04x %5hu ", -1, -1, -1, -1, 0, 0 );
  }

  // make sure that there is just one printf()
  if ( meta && (findings = meta->search( STORE_META_URL )) ) {
    return printf( "%s %3d %8ld %s %s %s\n", 
		   fn, code, size, md5, timeb, findings->data );
  } else {
    return printf( "%s %3d %8ld %s %s strange_file\n", 
		   fn, code, size, md5, timeb );
  }
}

// o.k., this is pure lazyness...
