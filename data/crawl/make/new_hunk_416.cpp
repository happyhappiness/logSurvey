
#define SYMBOL_EXTENSION        "_gmk_setup"

#include "debug.h"
#include "filedef.h"
#include "variable.h"

static load_func_t
load_object (const gmk_floc *flocp, int noerror,
             const char *ldname, const char *symname)
{
  static void *global_dl = NULL;
  load_func_t symp;

  if (! global_dl)
    {
      global_dl = dlopen (NULL, RTLD_NOW|RTLD_GLOBAL);
      if (! global_dl)
        fatal (flocp, _("Failed to open global symbol table: %s"), dlerror());
    }

  symp = (load_func_t) dlsym (global_dl, symname);
  if (! symp) {
    void *dlp = NULL;

    /* If the path has no "/", try the current directory first.  */
    if (! strchr (ldname, '/'))
      dlp = dlopen (concat (2, "./", ldname), RTLD_LAZY|RTLD_GLOBAL);

    /* If we haven't opened it yet, try the default search path.  */
    if (! dlp)
      dlp = dlopen (ldname, RTLD_LAZY|RTLD_GLOBAL);

    /* Still no?  Then fail.  */
    if (! dlp)
      {
        if (noerror)
          DB (DB_BASIC, ("%s", dlerror()));
        else
          error (flocp, "%s", dlerror());
        return NULL;
      }

    symp = dlsym (dlp, symname);
    if (! symp)
      fatal (flocp, _("Failed to load symbol %s from %s: %s"),
             symname, ldname, dlerror());
  }

  return symp;
}

int
load_file (const gmk_floc *flocp, const char **ldname, int noerror)
{
  int nmlen = strlen (*ldname);
  char *new = alloca (nmlen + CSTRLEN (SYMBOL_EXTENSION) + 1);
  char *symname = NULL;
  char *loaded;
  const char *fp;
  int r;
  load_func_t symp;

  /* Break the input into an object file name and a symbol name.  If no symbol
     name was provided, compute one from the object file name.  */
  fp = strchr (*ldname, '(');
  if (fp)
    {
