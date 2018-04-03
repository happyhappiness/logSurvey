
bool
action( int fd, size_t metasize,
	const char* fn, const char* url, const SquidMetaList& meta )
  // purpose: if cmdline-requested, send the purge request to the cache
  // paramtr: fd (IN): open FD for the object file
  //	      metasize (IN): offset into data portion of file (meta data size)
  //          fn (IN): name of the object file
  //          url (IN): URL string stored in the object file
  //	      meta (IN): list containing further meta data
  // returns: true for a successful action, false otherwise. The action
  //          may just print the file, send the purge request or even
  //          remove unwanted files.
  // globals: ::purgeMode (IN):  bit#0 set -> send purge request.
  //                             bit#1 set -> remove 404 object files.
  //          ::serverHost (IN): cache host address
  //          ::serverPort (IN): cache port number
{
  static const char* schablone = "PURGE %s HTTP/1.0\r\nAccept: */*\r\n\r\n";
  struct stat st;
  long size = ( fstat(fd,&st) == -1 ? -1 : long(st.st_size - metasize) );  
  int status = 0;

  // if we want to copy out the file, do that first of all.
  if ( ::copydir && *copydir && size > 0 ) 
    copy_out( st.st_size, metasize, ::debug, 
	      fn, url, ::copydir, ::envelope );
  
  // do we need to PURGE the file, yes, if purgemode bit#0 was set.
  if ( ::purgeMode & 0x01 ) {
    unsigned long bufsize = strlen(url) + strlen(schablone) + 4;
    char* buffer = new char[bufsize];

    sprintf( buffer, schablone, url );
    int sockfd = connectTo( serverHost, serverPort, true );
    if ( sockfd == -1 ) {
      fprintf( stderr, "unable to connect to server: %s\n", strerror(errno) );
      delete[] buffer;
      return false;
    }
    
    int size = strlen(buffer);
    if ( write( sockfd, buffer, size ) != size ) {
      // error while talking to squid
      fprintf( stderr, "unable to talk to server: %s\n", strerror(errno) );
      close(sockfd);
      delete[] buffer;
      return false;
    }
    memset( buffer+8, 0, 4 );
    if ( read( sockfd, buffer, bufsize ) < 1 ) {
      // error while reading squid's answer
      fprintf( stderr, "unable to read answer: %s\n", strerror(errno) );
      close(sockfd);
      delete[] buffer;
      return false;
    }
    close(sockfd);
    status = strtol(buffer+8,0,10);
    delete[] buffer;
  }
  
  // log the output of our operation
  bool flag = true;
  if ( ::verbose ) flag = ( log_extended( fn, status, size, &meta ) >= 0 );
  else flag = ( log_output( fn, status, size, url ) >= 0 );

  // remove the file, if purgemode bit#1, and HTTP result status 404).
  if ( (::purgeMode & 0x02) && status == 404 ) {
    reminder = true;
    if ( unlink(fn) == -1 )
      // error while unlinking file, this may happen due to the cache
      // unlinking a file while it is still in the readdir() cache of purge.
      fprintf( stderr, "WARNING: unable to unlink %s: %s\n",
	       fn, strerror(errno) );
  }
  
  return flag;
}

bool
match( const char* fn, const REList* list )
  // purpose: do something with the given cache content filename
  // paramtr: fn (IN): filename of cache file
  // returns: true for successful action, false otherwise.
  // warning: only return false, if you want the loop to terminate!
{
  static const size_t addon = sizeof(unsigned char) + sizeof(unsigned int);
  bool flag = true;
  
  if ( debug & 0x01 ) fprintf( stderr, "# [3] %s\n", fn );
  int fd = open( fn, O_RDONLY );
  if ( fd != -1 ) {
    if ( read(fd,::linebuffer,::buffersize-1) > 60 ) {
      ::linebuffer[ ::buffersize-1 ] = '\0'; // force-terminate string

      // check the offset into the start of object data. The offset is
      // stored in a host endianess after the first byte.
      unsigned int datastart;
      memcpy( &datastart, ::linebuffer + 1, sizeof(unsigned int) );
      if ( datastart > ::buffersize - addon - 1 ) {
	// check offset into server reply header (start of cache data).
	fputs( "WARNING: Using a truncated URL string.\n", stderr );
	datastart = ::buffersize - addon - 1;
      }

      // NEW: Parse squid meta data, which is a kind of linked list
      // flattened out into a file byte stream. Somewhere within is
      // the URL as part of the list. First, gobble all meta data.
      unsigned int offset = addon;
      SquidMetaList meta;
      while ( offset + addon <= datastart ) {
	unsigned int size = 0;
	memcpy( &size, linebuffer+offset+sizeof(char), sizeof(unsigned int) );
	meta.append( SquidMetaType(*(linebuffer+offset)),
		     size, linebuffer+offset+addon );
	offset += ( addon + size );
      }

      // Now extract the key URL from the meta data.
      const SquidTLV* urlmeta = meta.search( STORE_META_URL );
      if ( urlmeta ) {
	// found URL in meta data. Try to process the URL
	if ( list == 0 )
	  flag = action( fd, datastart, fn, (char*) urlmeta->data, meta );
	else {
	  REList* head = (REList*) list; // YUCK!
	  while ( head != 0 ) {
	    if ( head->match( (char*) urlmeta->data ) ) break;
	    head = head->next;
	  }
	  if ( head != 0 )
	    flag = action( fd, datastart, fn, (char*) urlmeta->data, meta );
	  else flag = true;
	}
      }

      // "meta" will be deleted when exiting from this block
    } else {
      // weird file, FIXME: stat() it!
      struct stat st;
      long size = ( fstat(fd,&st) == -1 ? -1 : st.st_size );
      if ( ::verbose ) flag = ( log_extended( fn, -1, size, 0 ) >= 0 );
      else flag = ( log_output( fn, -1, size, "strange file" ) >= 0 );

      if ( (::purgeMode & 0x04) ) {
	reminder = true;
	if ( unlink(fn) == -1 )
	  // error while unlinking file, this may happen due to the cache
	  // unlinking a file while it is in the readdir() cache of purge.
	  fprintf( stderr, "WARNING: unable to unlink %s: %s\n",
		   fn, strerror(errno) );
      }
    }
    close(fd);
  } else {
    // error while opening file, this may happen due to the cache
    // unlinking a file while it is still in the readdir() cache of purge.
    fprintf( stderr, "WARNING: open \"%s\": %s\n", fn, strerror(errno) );
  }
  
  return flag;
}

bool
filelevel( const char* directory, const REList* list )
  // purpose: from given starting point, look for squid xxxxxxxx files.
  // example: "/var/spool/cache/08/7F" as input, do action over files
  // paramtr: directory (IN): starting point
  //          list (IN): list of rexps to match URLs against
  // returns: true, if every subdir && action was successful.
{
  struct dirent* entry;
  if ( debug & 0x01 )
    fprintf( stderr, "# [2] %s\n", directory );

  DIR* dir = opendir( directory );
  if ( dir == NULL ) {
    fprintf( stderr, "unable to open directory \"%s\": %s\n", 
	     directory, strerror(errno) );
    return false;
  }

  // display a rotating character as "i am alive" signal (slows purge).
  if ( ::iamalive ) {
    static char alivelist[4][3] = { "\\\b", "|\b", "/\b", "-\b" };
    static unsigned short alivecount = 0;
    assert( write( STDOUT_FILENO, alivelist[alivecount++ & 3], 2 ) == 2 );
  }

  bool flag = true;
  while ( (entry=readdir(dir)) && flag ) {
    if ( isxstring(entry->d_name,8) ) {
      char* name = concat( directory, "/", entry->d_name, 0 );
      flag = match( name, list );
      delete[] name;
    }
  }

  closedir(dir);
  return flag;
}

bool
dirlevel( const char* dirname, const REList* list, bool level=false )
  // purpose: from given starting point, look for squid 00..FF directories.
  // paramtr: dirname (IN): starting point
  //          list (IN): list of rexps to match URLs against
  //          level (IN): false==toplevel, true==1st level
  // example: "/var/spool/cache", false as input, traverse subdirs w/ action.
  // example: "/var/spool/cache/08", true as input, traverse subdirs w/ action.
  // returns: true, if every subdir && action was successful.
  // warning: this function is once-recursive, no deeper.
{
  struct dirent* entry;
  if ( debug & 0x01 )
    fprintf( stderr, "# [%d] %s\n", (level ? 1 : 0), dirname );

  DIR* dir = opendir( dirname );
  if ( dir == NULL ) {
    fprintf( stderr, "unable to open directory \"%s\": %s\n", 
	     dirname, strerror(errno) );
    return false;
  }
  
  bool flag = true;
  while ( (entry=readdir(dir)) && flag ) {
    if ( strlen(entry->d_name) == 2 &&
	 isxdigit(entry->d_name[0]) &&
	 isxdigit(entry->d_name[1]) ) {
      char* name = concat( dirname, "/", entry->d_name, 0 );
      flag = level ? filelevel( name, list ) : dirlevel( name, list, true );
      delete[] name;
    }
  }

  closedir(dir);
  return flag;
}

int
checkForPortOnly( const char* optarg )
  // purpose: see if somebody just put in a port instead of a hostname
  // paramtr: optarg (IN): argument from commandline
  // returns: 0..65535 is the valid port number in network byte order,
  //          -1 if not a port
{
  // if there is a period in there, it must be a valid hostname
  if ( strchr( optarg, '.' ) != 0 ) return -1;

  // if it is just a number between 0 and 65535, it must be a port
  char* errstr = 0;
  unsigned long result = strtoul( optarg, &errstr, 0 );
  if ( result < 65536 && errstr != optarg ) return htons(result);

#if 0
  // one last try, test for a symbolical service name
  struct servent* service = getservbyname( optarg, "tcp" );
  return service ? service->s_port : -1;
#else
  return -1;
#endif
}

void
helpMe( void )
  // purpuse: write help message and exit
{
  printf( "\n%s\nUsage:\t%s\t[-a] [-c cf] [-d l] [-(f|F) fn | -(e|E) re] "
	  "[-p h[:p]]\n\t\t[-P #] [-s] [-v] [-C dir [-H]] [-n]\n\n",
	  ::RCS_ID, ::programname );
  printf(
" -a\tdisplay a little rotating thingy to indicate that I am alive (tty only).\n"
" -c c\tsquid.conf location, default \"%s\".\n"
" -C dir\tbase directory for content extraction (copy-out mode).\n"
" -d l\tdebug level, an OR of different debug options.\n"
" -e re\tsingle regular expression per -e instance (use quotes!).\n"
" -E re\tsingle case sensitive regular expression like -e.\n"
" -f fn\tname of textfile containing one regular expression per line.\n"
" -F fn\tname of textfile like -f containing case sensitive REs.\n"
" -H\tprepend HTTP reply header to destination files in copy-out mode.\n"
" -n\tdo not fork() when using more than one cache_dir.\n"
" -p h:p\tcache runs on host h and optional port p, default is %s:%u.\n"
" -P #\tif 0, just print matches; otherwise OR the following purge modes:\n"
"\t   0x01 really send PURGE to the cache.\n"
"\t   0x02 remove all caches files reported as 404 (not found).\n"
"\t   0x04 remove all weird (inaccessible or too small) cache files.\n"
"\t0 and 1 are recommended - slow rebuild your cache with other modes.\n"
" -s\tshow all options after option parsing, but before really starting.\n"
" -v\tshow more information about the file, e.g. MD5, timestamps and flags.\n"
"\n", DEFAULT_SQUID_CONF, DEFAULTHOST, DEFAULTPORT );

}

void
parseCommandline( int argc, char* argv[], REList*& head,
		  char*& conffile, char*& copydir,
		  struct in_addr& serverHost, unsigned short& serverPort )
  // paramtr: argc: see ::main().
  //          argv: see ::main().
  // returns: Does terminate the program on errors!
  // purpose: suck in any commandline options, and set the global vars.
{ int option, port, showme = 0;
  char* ptr, *colon;
  FILE* rfile;

  // program basename
  if ( (ptr = strrchr(argv[0],'/')) == NULL ) ptr=argv[0];
  else ptr++;
  ::programname = ptr;

  // extract commandline parameters
  REList* tail = head = 0;
  opterr = 0;
  while ( (option = getopt( argc, argv, "ac:C:d:E:e:F:f:Hnp:P:sv" )) != -1 ) {
    switch ( option ) {
    case 'a':
      ::iamalive = ! ::iamalive;
      break;
    case 'C':
      if ( optarg && *optarg ) {
	if ( copydir ) free( (void*) copydir );
	assert( (copydir = strdup(optarg)) );
      }
      break;
    case 'c':
      if ( optarg && *optarg ) {
	if ( *conffile ) free((void*) conffile );
	assert( (conffile = strdup(optarg)) );
      }
      break;

    case 'd':
      ::debug = strtoul( optarg, 0, 0 );
      break;

    case 'E':
    case 'e':
      if ( head == 0 ) tail = head = new REList( optarg, option=='E' );
      else {
	tail->next = new REList( optarg, option=='E' );
	tail = tail->next;
      }
      break;
      
    case 'f':
      if ( (rfile = fopen( optarg, "r" )) != NULL ) {
	unsigned long lineno = 0;
#define LINESIZE 512
	char line[LINESIZE];
	while ( fgets( line, LINESIZE, rfile ) != NULL ) {
	  lineno++;
	  int len = strlen(line)-1;
	  if ( len+2 >= LINESIZE ) {
	    fprintf( stderr, "%s:%lu: line too long, sorry.\n",
		     optarg, lineno );
	    exit(1);
	  }

	  // remove trailing line breaks
	  while ( len > 0 && ( line[len] == '\n' || line[len] == '\r' ) )
	    line[len--] = '\0';

	  // insert into list of expressions
	  if ( head == 0 ) tail = head = new REList(line,option=='F');
	  else {
	    tail->next = new REList(line,option=='F');
	    tail = tail->next;
	  }
	}
	fclose(rfile);
      } else
	fprintf( stderr, "unable to open %s: %s\n", optarg, strerror(errno));
      break;

    case 'H':
      ::envelope = ! ::envelope;
      break;
    case 'n':
      ::no_fork = ! ::no_fork;
      break;
    case 'p':
      colon = strchr( optarg, ':' );
      if ( colon == 0 ) {
	// no colon, only look at host

	// fix: see if somebody just put in there a port (no periods)
	// give port number precedence over host names
	port = checkForPortOnly( optarg );
	if ( port == -1 ) {
	  // assume that main() did set the default port
	  if ( convertHostname(optarg,serverHost) == -1 ) {
	    fprintf( stderr, "unable to resolve host %s!\n", optarg );
	    exit(1);
	  }
	} else {
	  // assume that main() did set the default host
	  serverPort = port;
	}
      } else {
	// colon used, port is extra
	*colon++ = 0;
	if ( convertHostname(optarg,serverHost) == -1 ) {
	  fprintf( stderr, "unable to resolve host %s!\n", optarg );
	  exit(1);
	}
	if ( convertPortname(colon,serverPort) == -1 ) {
	  fprintf( stderr, "unable to resolve port %s!\n", colon );
	  exit(1);
	}
      }
      break;
    case 'P':
      ::purgeMode = ( strtol( optarg, 0, 0 ) & 0x07 );
      break;
    case 's':
      showme=1;
      break;
    case 'v':
      ::verbose = ! ::verbose;
      break;
    case '?':
    default:
      helpMe();
      exit(1);
    }
  }

  // adjust
  if ( ! isatty(fileno(stdout)) || (::debug & 0x01) ) ::iamalive = false;
  if ( head == 0 ) {
    fputs( "There was no regular expression defined. If you intend\n", stderr );
    fputs( "to match all possible URLs, use \"-e .\" instead.\n", stderr );
    exit(1);
  }

  // postcondition: head != 0
  assert( head != 0 );

  // make sure that the copy out directory is there and accessible
  if ( copydir && *copydir )
    if ( assert_copydir( copydir ) != 0 ) exit(1);
  
  // show results
  if ( showme ) {
    printf( "#\n# Currently active values for %s:\n# %s\n", 
	    ::programname, ::RCS_ID );
    printf( "# Debug level       : " );
    if ( ::debug ) printf( "%#6.4hx", ::debug );
    else printf( "production level" ); // printf omits 0x prefix for 0!
    printf( " + %s mode", ::no_fork ? "linear" : "parallel" );
    puts( ::verbose ? " + extra verbosity" : "" );

    printf( "# Copy-out directory: %s ", 
	    copydir ? copydir : "copy-out mode disabled" );
    if ( copydir ) 
      printf( "(%s HTTP header)\n", ::envelope ? "prepend" : "no" );
    else
      puts("");
    
    printf( "# Squid config file : %s\n", conffile );
    printf( "# Cacheserveraddress: %s:%u\n",
	    inet_ntoa( serverHost ), ntohs( serverPort ) );
    printf( "# purge mode        : 0x%02x\n", ::purgeMode );
    printf( "# Regular expression: " );

    unsigned count(0);
    for ( tail = head; tail != NULL; tail = tail->next ) {
      if ( count++ ) printf( "#%22u", count );
#if defined(LINUX) && putc==_IO_putc
      // I HATE BROKEN LINUX HEADERS!
      // purge.o(.text+0x1040): undefined reference to `_IO_putc'
      // If your compilation breaks here, remove the undefinition
#undef putc      
#endif
      else putchar('1');
      printf( " \"%s\"\n", tail->data );
    }
    puts( "#" );
  }
  fflush( stdout );
}

extern "C" {

static
void
exiter( void )
{
  if ( ::term_flag ) psignal( ::term_flag, "received signal" );
  delete[] ::linebuffer;
  if ( ::reminder ) {
    fputs( 
"WARNING! Caches files were removed. Please shut down your cache, remove\n"
"your swap.state files and restart your cache again, i.e. effictively do\n"
"a slow rebuild your cache! Otherwise your squid *will* choke!\n", stderr );
  }
}

static
void
handler( int signo )
{
  ::term_flag = signo;
  if ( getpid() == getpgrp() ) kill( -getpgrp(), signo );
  exit(1);
}

} // extern "C"

static
int
makelinebuffered( FILE* fp, const char* fn = 0 )
  // purpose: make the given FILE line buffered
  // paramtr: fp (IO): file pointer which to put into line buffer mode
  //          fn (IN): name of file to print in case of error
  // returns: 0 is ok, -1 to indicate an error
  // warning: error messages will already be printed
{
  if ( setvbuf( fp, 0, _IOLBF, 0 ) == 0 ) {
    // ok
    return 0;
  } else {
    // error
    fprintf( stderr, "unable to make \"%s\" line buffered: %s\n",
	     fn ? fn : "", strerror(errno) );
    return -1;
  }
}

int
main( int argc, char* argv[] )
{
  // setup variables
  REList* list = 0;
  char* conffile = strdup( DEFAULT_SQUID_CONF );
  serverPort = htons(DEFAULTPORT);
  if ( convertHostname(DEFAULTHOST,serverHost) == -1 ) {
    fprintf( stderr, "unable to resolve host %s!\n", DEFAULTHOST );
    return 1;
  }

  // setup line buffer
  ::linebuffer = new char[ ::buffersize ];
  assert( ::linebuffer != 0 );
  
  // parse commandline
  puts( "### Use at your own risk! No guarantees whatsoever. You were warned. ###");
  parseCommandline( argc, argv, list, conffile, ::copydir,
		    serverHost, serverPort );

  // prepare execution
  if ( atexit( exiter ) != 0 ||
       Signal( SIGTERM, handler, true ) == SIG_ERR ||
       Signal( SIGINT, handler, true ) == SIG_ERR ||
       Signal( SIGHUP, handler, true ) == SIG_ERR ) {
    perror( "unable to install signal/exit function" );
    return 1;
  }

  // try to read squid.conf file to determine all cache_dir locations
  CacheDirVector cdv(0);
  if ( readConfigFile( cdv, conffile, debug ? stderr : 0 ) > 0 ) {
    // there are some valid cache_dir entries. 
    // unless forking was forbidden by cmdline option, 
    // for a process for each cache_dir entry to remove files.

    if ( ::no_fork || cdv.size() == 1 ) {
      // linear mode, one cache_dir after the next
      for ( CacheDirVector::iterator i = cdv.begin(); i != cdv.end(); ++i ) {
	// execute OR complain
	if ( ! dirlevel(i->base,list) )
	  fprintf( stderr, "program terminated due to error: %s", 
		   strerror(errno) );
	free((void*) i->base);
      }
    } else {
      // parallel mode, all cache_dir in parallel
      pid_t* child = new pid_t[ cdv.size() ];

      // make stdout/stderr line bufferd
      makelinebuffered( stdout, "stdout" );
      makelinebuffered( stderr, "stderr" );

      // make parent process group leader for easier killings
      if ( setpgid(getpid(), getpid()) != 0 ) {
	perror( "unable to set process group leader" );
	return 1;
      }

      // -a is mutually exclusive with fork mode
      if ( ::iamalive ) {
	puts( "# i-am-alive flag incompatible with fork mode, resetting" );
	::iamalive = false;
      }

      for ( int i=0; i < cdv.size(); ++i ) {
	if ( getpid() == getpgrp() ) { 
	  // only parent == group leader may fork off new processes
	  if ( (child[i]=fork()) < 0 ) {
	    // fork error, this is bad!
	    perror( "unable to fork" );
	    kill( -getpgrp(), SIGTERM );
	    return 1;
	  } else if ( child[i] == 0 ) {
	    // child mode
	    // execute OR complain
	    if ( ! dirlevel(cdv[i].base,list) )
	      fprintf( stderr, "program terminated due to error: %s\n", 
		       strerror(errno) );
	    free((void*) cdv[i].base);
	    return 0;
	  } else {
	    // parent mode
	    if ( ::debug ) printf( "forked child %d\n", (int) child[i] );
	  }
	}
      } 

      // collect the garbase
      pid_t temp;
      int status;
      for ( int i=0; i < cdv.size(); ++i ) {
	while ( (temp=waitpid( (pid_t)-1, &status, 0 )) == -1 )
	  if ( errno == EINTR ) continue;
	if ( ::debug ) printf( "collected child %d\n", (int) temp );
      }
      delete[] child;
    }
  } else {
    fprintf( stderr, "no cache_dir or error accessing \"%s\"\n", conffile );
  }

  // clean up
  if ( copydir ) free( (void*) copydir );
  free((void*) conffile);
  delete list;
  return 0;
}
