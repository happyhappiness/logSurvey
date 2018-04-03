
/* useful for temporary debuging messages, delete it later @?@ */
#define here __FILE__,__LINE__
#define dev_null 1 ? ((void)0) :
#ifdef HAVE_SYSLOG
#define tmp_debug(fl) _db_level = 0, dev_null _db_print("%s:%d: ",fl), dev_null _db_print
#else
