
#define SYMBOL_EXTENSION        "_gmk_setup"

static void *global_dl = NULL;

#include "debug.h"
#include "filedef.h"
#include "variable.h"

static int
init_symbol (const gmk_floc *flocp, const char *ldname, load_func_t symp)
{
  int r;
  const char *p;
  int nmlen = strlen (ldname);
  char *loaded = allocated_variable_expand("$(.LOADED)");

  /* If it's already been loaded don't do it again.  */
  p = strstr (loaded, ldname);
  r = p && (p==loaded || p[-1]==' ') && (p[nmlen]=='\0' || p[nmlen]==' ');
  free (loaded);
  if (r)
    return 1;

  /* Now invoke the symbol.  */
  r = (*symp) (flocp);

  /* If it succeeded, add the symbol to the loaded variable.  */
  if (r > 0)
    do_variable_definition (flocp, ".LOADED", ldname, o_default, f_append, 0);

  return r;
}

int
load_file (const gmk_floc *flocp, const char **ldname, int noerror)
{
  load_func_t symp;
  const char *fp;
  char *symname = NULL;
  char *new = alloca (strlen (*ldname) + CSTRLEN (SYMBOL_EXTENSION) + 1);

  if (! global_dl)
    {
      global_dl = dlopen (NULL, RTLD_NOW|RTLD_GLOBAL);
      if (! global_dl)
        fatal (flocp, _("Failed to open global symbol table: %s"), dlerror());
    }

  /* If a symbol name was provided, use it.  */
  fp = strchr (*ldname, '(');
  if (fp)
    {
