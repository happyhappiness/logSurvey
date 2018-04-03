/* Verify the integrity of the data base of files.  */

#define VERIFY_CACHED(_p,_n) \
    do{\
        if (_p->_n && _p->_n[0] && !strcache_iscached (_p->_n)) \
          error (NULL, _("%s: Field '%s' not cached: %s"), _p->name, # _n, _p->_n); \
    }while(0)

static void
