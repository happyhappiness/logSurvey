 *   #define STUB_API "foo/libexample.la"
 *   #include "tests/STUB.h"
 */

/// macro to stub a void function.
#define STUB { fatal(STUB_API " required"); }

/** macro to stub a function with return value.
 *  Aborts unit tests requiring its definition with a message about the missing linkage
 */
#define STUB_RETVAL(x) { fatal(STUB_API " required"); return x; }

/** macro to stub a function which returns a reference to dynamic
 *  Aborts unit tests requiring its definition with a message about the missing linkage
 *  This macro uses 'new x' to construct a stack vailable for the reference, may leak.
 *  \param x may be the type to define or a constructor call with parameter values
 */
#define STUB_RETREF(x) { fatal(STUB_API " required"); return new x; }

/** macro to stub a function which returns a reference to static
 *  Aborts unit tests requiring its definition with a message about the missing linkage
 *  This macro uses static variable definition to avoid leaks.
 *  \param x  the type name to define
 */
#define STUB_RETSTATREF(x) { fatal(STUB_API " required"); static x v; return v; }

#endif /* STUB */
