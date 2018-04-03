 #include <credef.h>
 #include <descrip.h>
 #include <ctype.h>
+#include <ssdef.h>
+#include <stsdef.h>
+#include <rmsdef.h>
+globalvalue unsigned int LBR$_HDRTRUNC;
+
 #if __DECC
 #include <unixlib.h>
 #include <lbr$routines.h>
 #endif
+const char *
+vmsify (const char *name, int type);
+
+/* Time conversion from VMS to Unix
+   Conversion from local time (stored in library) to GMT (needed for gmake)
+   Note: The tm_gmtoff element is a VMS extension to the ANSI standard. */
+static time_t
+vms_time_to_unix(void *vms_time)
+{
+  struct tm *tmp;
+  time_t unix_time;
 
-static void *VMS_lib_idx;
+  unix_time = decc$fix_time(vms_time);
+  tmp = localtime(&unix_time);
+  unix_time -= tmp->tm_gmtoff;
 
-static const char *VMS_saved_memname;
+  return unix_time;
+}
+
+
+/* VMS library routines need static variables for callback */
+static void *VMS_lib_idx;
 
-static time_t VMS_member_date;
+static const void *VMS_saved_arg;
 
 static long int (*VMS_function) ();
 
+static long int VMS_function_ret;
+
+
+/* This is a callback procedure for lib$get_index */
 static int
-VMS_get_member_info (struct dsc$descriptor_s *module, unsigned long *rfa)
+VMS_get_member_info(struct dsc$descriptor_s *module, unsigned long *rfa)
 {
   int status, i;
-  long int fnval;
-
-  time_t val;
+  const int truncated = 0; /* Member name may be truncated */
+  time_t member_date; /* Member date */
+  char *filename;
+  unsigned int buffer_length; /* Actual buffer length */
+
+  /* Unused constants - Make does not actually use most of these */
+  const int file_desc = -1; /* archive file descriptor for reading the data */
+  const int header_position = 0; /* Header position */
+  const int data_position = 0; /* Data position in file */
+  const int data_size = 0; /* Data size */
+  const int uid = 0; /* member gid */
+  const int gid = 0; /* member gid */
+  const int mode = 0; /* member protection mode */
+  /* End of unused constants */
 
   static struct dsc$descriptor_s bufdesc =
     { 0, DSC$K_DTYPE_T, DSC$K_CLASS_S, NULL };
 
+  /* Only need the module definition */
   struct mhddef *mhd;
-  char filename[128];
 
-  bufdesc.dsc$a_pointer = filename;
-  bufdesc.dsc$w_length = sizeof (filename);
+  /* If a previous callback is non-zero, just return that status */
+  if (VMS_function_ret)
+    {
+      return SS$_NORMAL;
+    }
+
+  /* lbr_set_module returns more than just the module header. So allocate
+     a buffer which is big enough: the maximum LBR$C_MAXHDRSIZ. That's at
+     least bigger than the size of struct mhddef.
+     If the request is too small, a buffer truncated warning is issued so
+     it can be reissued with a larger buffer.
+     We do not care if the buffer is truncated, so that is still a success. */
+  mhd = xmalloc(LBR$C_MAXHDRSIZ);
+  bufdesc.dsc$a_pointer = (char *) mhd;
+  bufdesc.dsc$w_length = LBR$C_MAXHDRSIZ;
+
+  status = lbr$set_module(&VMS_lib_idx, rfa, &bufdesc, &buffer_length, 0);
 
-  status = lbr$set_module (&VMS_lib_idx, rfa, &bufdesc,
-                           &bufdesc.dsc$w_length, 0);
-  if (! (status & 1))
+  if ((status != LBR$_HDRTRUNC) && !$VMS_STATUS_SUCCESS(status))
     {
-      ON (error, NILF,
+      ON(error, NILF,
           _("lbr$set_module() failed to extract module info, status = %d"),
           status);
 
-      lbr$close (&VMS_lib_idx);
+      lbr$close(&VMS_lib_idx);
 
-      return 0;
+      return status;
     }
 
-  mhd = (struct mhddef *) filename;
-
-#ifdef __DECC
-  /* John Fowler <jfowler@nyx.net> writes this is needed in his environment,
-   * but that decc$fix_time() isn't documented to work this way.  Let me
-   * know if this causes problems in other VMS environments.
-   */
-  {
-    /* Modified by M. Gehre at 11-JAN-2008 because old formula is wrong:
-     * val = decc$fix_time (&mhd->mhd$l_datim) + timezone - daylight*3600;
-     * a) daylight specifies, if the timezone has daylight saving enabled, not
-     *    if it is active
-     * b) what we need is the information, if daylight saving was active, if
-     *    the library module was replaced. This information we get using the
-     *    localtime function
-     */
-
-    struct tm *tmp;
-
-    /* Conversion from VMS time to C time */
-    val = decc$fix_time (&mhd->mhd$l_datim);
-
-    /*
-     * Conversion from local time (stored in library) to GMT (needed for gmake)
-     * Note: The tm_gmtoff element is a VMS extension to the ANSI standard.
-     */
-    tmp = localtime (&val);
-    val -= tmp->tm_gmtoff;
-  }
+#ifdef TEST
+  /* When testing this code, it is useful to know the length returned */
+  printf("Input length = %d, actual = %d\n",
+      bufdesc.dsc$w_length, buffer_length);
 #endif
 
+  /* Conversion from VMS time to C time.
+     VMS defectlet - mhddef is sub-optimal, for the time, it has a 32 bit
+     longword, mhd$l_datim, and a 32 bit fill instead of two longwords, or
+     equivalent. */
+  member_date = vms_time_to_unix(&mhd->mhd$l_datim);
+  free(mhd);
+
+  /* Here we have a problem.  The module name on VMS does not have
+     a file type, but the filename pattern in the "VMS_saved_arg"
+     may have one.
+     But only the method being called knows how to interpret the
+     filename pattern.
+     There are currently two different formats being used.
+     This means that we need a VMS specific code in those methods
+     to handle it. */
+  filename = xmalloc(module->dsc$w_length + 1);
+
+  /* TODO: We may need an option to preserve the case of the module
+     For now force the module name to lower case */
   for (i = 0; i < module->dsc$w_length; i++)
-    filename[i] = _tolower ((unsigned char)module->dsc$a_pointer[i]);
+    filename[i] = _tolower((unsigned char )module->dsc$a_pointer[i]);
 
   filename[i] = '\0';
 
-  VMS_member_date = (time_t) -1;
+  VMS_function_ret = (*VMS_function)(file_desc, filename, truncated,
+      header_position, data_position, data_size, member_date, uid, gid, mode,
+      VMS_saved_arg);
 
-  fnval =
-    (*VMS_function) (-1, filename, 0, 0, 0, 0, val, 0, 0, 0,
-                     VMS_saved_memname);
-
-  if (fnval)
-    {
-      VMS_member_date = fnval;
-      return 0;
-    }
-  else
-    return 1;
+  free(filename);
+  return SS$_NORMAL;
 }
 
+
 /* Takes three arguments ARCHIVE, FUNCTION and ARG.
 
    Open the archive named ARCHIVE, find its members one by one,
