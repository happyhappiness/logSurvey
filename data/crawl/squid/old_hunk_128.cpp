
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
    :next(0),data(xstrdup(what))
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
    if ( data ) xfree((void*) data);
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

