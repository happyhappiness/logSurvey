
#ifndef	NO_ARCHIVES

#ifdef VMS
#include <lbrdef.h>
#include <mhddef.h>
#include <credef.h>
#include <descrip.h>
#include <ctype.h>
#if __DECC
#include <unixlib.h>
#include <lbr$routines.h>
#endif

#define uppercasify(str) {char *str1; for (str1 = str; *str1; str1++) *str1 = _toupper(*str1);}

static void *VMS_lib_idx;

static char *VMS_saved_memname;

static time_t VMS_member_date;

static long int (*VMS_function) ();

static int
VMS_get_member_info (module, rfa)
     struct dsc$descriptor_s *module;
     unsigned long *rfa;
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
  if (! status)
    {
      error ("lbr$set_module failed to extract module info, status = %d",
	     status);

      lbr$close (&VMS_lib_idx);

      return 0;
    }

  mhd = (struct mhddef *) filename;

  val = decc$fix_time (&mhd->mhd$l_datim);

  for (i = 0; i < module->dsc$w_length; i++)
    filename[i] = _tolower (module->dsc$a_pointer[i]);

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
   and for each one call FUNCTION with the following arguments:
     archive file descriptor for reading the data,
     member name,
     member name might be truncated flag,
     member header position in file,
     member data position in file,
     member data size,
     member date,
     member uid,
     member gid,
     member protection mode,
     ARG.

   NOTE: on VMS systems, only name, date, and arg are meaningful!

   The descriptor is poised to read the data of the member
   when FUNCTION is called.  It does not matter how much
   data FUNCTION reads.

   If FUNCTION returns nonzero, we immediately return
   what FUNCTION returned.

   Returns -1 if archive does not exist,
   Returns -2 if archive has invalid format.
   Returns 0 if have scanned successfully.  */

long int
ar_scan (archive, function, arg)
     char *archive;
     long int (*function) ();
     long int arg;
{
  char *p;

  static struct dsc$descriptor_s libdesc =
    { 0, DSC$K_DTYPE_T, DSC$K_CLASS_S, NULL };

  unsigned long func = LBR$C_READ;
  unsigned long type = LBR$C_TYP_UNK;
  unsigned long index = 1;

  int status;

  status = lbr$ini_control (&VMS_lib_idx, &func, &type, 0);

  if (! status)
    {
      error ("lbr$ini_control failed with status = %d",status);
      return -2;
    }

  libdesc.dsc$a_pointer = archive;
  libdesc.dsc$w_length = strlen (archive);

  status = lbr$open (&VMS_lib_idx, &libdesc, 0, 0, 0, 0, 0);

  if (! status)
    {
      error ("unable to open library `%s' to lookup member `%s'",
	     archive, (char *)arg);
      return -1;
    }

  VMS_saved_memname = (char *)arg;

  /* For comparison, delete .obj from arg name.  */

  p = rindex (VMS_saved_memname, '.');
  if (p)
    *p = '\0';

  VMS_function = function;

  lbr$get_index (&VMS_lib_idx, &index, VMS_get_member_info, 0);

  /* Undo the damage.  */
  if (p)
    *p = '.';

  lbr$close (&VMS_lib_idx);

  return VMS_member_date > 0 ? VMS_member_date : 0;
}

#else /* !VMS */

/* SCO Unix's compiler defines both of these.  */
#ifdef	M_UNIX
#undef	M_XENIX
