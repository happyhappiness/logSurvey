#include <credef.h>
#include <descrip.h>
#include <ctype.h>
#if __DECC
#include <unixlib.h>
#include <lbr$routines.h>
#endif

static void *VMS_lib_idx;

static const char *VMS_saved_memname;

static time_t VMS_member_date;

static long int (*VMS_function) ();

static int
VMS_get_member_info (struct dsc$descriptor_s *module, unsigned long *rfa)
{
  int status, i;
  long int fnval;

  time_t val;

  static struct dsc$descriptor_s bufdesc =
    { 0, DSC$K_DTYPE_T, DSC$K_CLASS_S, NULL };

  struct mhddef *mhd;
  char filename[128];

  bufdesc.dsc$a_pointer = filename;
  bufdesc.dsc$w_length = sizeof (filename);

  status = lbr$set_module (&VMS_lib_idx, rfa, &bufdesc,
                           &bufdesc.dsc$w_length, 0);
  if (! (status & 1))
    {
      ON (error, NILF,
          _("lbr$set_module() failed to extract module info, status = %d"),
          status);

      lbr$close (&VMS_lib_idx);

      return 0;
    }

  mhd = (struct mhddef *) filename;

#ifdef __DECC
  /* John Fowler <jfowler@nyx.net> writes this is needed in his environment,
   * but that decc$fix_time() isn't documented to work this way.  Let me
   * know if this causes problems in other VMS environments.
   */
  {
    /* Modified by M. Gehre at 11-JAN-2008 because old formula is wrong:
     * val = decc$fix_time (&mhd->mhd$l_datim) + timezone - daylight*3600;
     * a) daylight specifies, if the timezone has daylight saving enabled, not
     *    if it is active
     * b) what we need is the information, if daylight saving was active, if
     *    the library module was replaced. This information we get using the
     *    localtime function
     */

    struct tm *tmp;

    /* Conversion from VMS time to C time */
    val = decc$fix_time (&mhd->mhd$l_datim);

    /*
     * Conversion from local time (stored in library) to GMT (needed for gmake)
     * Note: The tm_gmtoff element is a VMS extension to the ANSI standard.
     */
    tmp = localtime (&val);
    val -= tmp->tm_gmtoff;
  }
#endif

  for (i = 0; i < module->dsc$w_length; i++)
    filename[i] = _tolower ((unsigned char)module->dsc$a_pointer[i]);

  filename[i] = '\0';

  VMS_member_date = (time_t) -1;

  fnval =
    (*VMS_function) (-1, filename, 0, 0, 0, 0, val, 0, 0, 0,
                     VMS_saved_memname);

  if (fnval)
    {
      VMS_member_date = fnval;
      return 0;
    }
  else
    return 1;
}

/* Takes three arguments ARCHIVE, FUNCTION and ARG.

   Open the archive named ARCHIVE, find its members one by one,
