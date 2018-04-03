/* Replacements for Posix functions and Posix functionality for MS-Windows.

Copyright (C) 2013 Free Software Foundation, Inc.
This file is part of GNU Make.

GNU Make is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later
version.

GNU Make is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <string.h>
#include <io.h>
#include <stdarg.h>
#include <errno.h>
#include <windows.h>

#include "makeint.h"
#include "job.h"

#ifdef OUTPUT_SYNC
/* Support for OUTPUT_SYNC and related functionality.  */

/* Emulation of fcntl that supports only F_GETFD and F_SETLKW.  */
int
fcntl (intptr_t fd, int cmd, ...)
{
  va_list ap;

  va_start (ap, cmd);

  switch (cmd)
    {
      case F_GETFD:
	va_end (ap);
	/* Could have used GetHandleInformation, but that isn't
	   supported on Windows 9X.  */
	if (_get_osfhandle (fd) == -1)
	  return -1;
	return 0;
      case F_SETLKW:
	{
	  void *buf = va_arg (ap, void *);
	  struct flock *fl = (struct flock *)buf;
	  HANDLE hmutex = (HANDLE)fd;
	  static struct flock last_fl;
	  short last_type = last_fl.l_type;

	  va_end (ap);

	  if (hmutex == INVALID_HANDLE_VALUE || !hmutex)
	    return -1;

	  last_fl = *fl;

	  switch (fl->l_type)
	    {

	      case F_WRLCK:
		{
		  DWORD result;

		  if (last_type == F_WRLCK)
		    {
		      /* Don't call WaitForSingleObject if we already
			 own the mutex, because doing so will require
			 us to call ReleaseMutex an equal number of
			 times, before the mutex is actually
			 released.  */
		      return 0;
		    }

		  result = WaitForSingleObject (hmutex, INFINITE);
		  switch (result)
		    {
		      case WAIT_OBJECT_0:
			/* We don't care if the mutex owner crashed or
			   exited.  */
		      case WAIT_ABANDONED:
			return 0;
		      case WAIT_FAILED:
		      case WAIT_TIMEOUT: /* cannot happen, really */
			{
			  DWORD err = GetLastError ();

			  /* Invalidate the last command.  */
			  memset (&last_fl, 0, sizeof (last_fl));

			  switch (err)
			    {
			      case ERROR_INVALID_HANDLE:
			      case ERROR_INVALID_FUNCTION:
				errno = EINVAL;
				return -1;
			      default:
				errno = EDEADLOCK;
				return -1;
			    }
			}
		    }
		}
	      case F_UNLCK:
		{
		  /* FIXME: Perhaps we should call ReleaseMutex
		     repatedly until it errors out, to make sure the
		     mutext is released even if we somehow managed to
		     to take ownership multiple times?  */
		  BOOL status = ReleaseMutex (hmutex);

		  if (status)
		    return 0;
		  else
		    {
		      DWORD err = GetLastError ();

		      if (err == ERROR_NOT_OWNER)
			errno = EPERM;
		      else
			{
			  memset (&last_fl, 0, sizeof (last_fl));
			  errno = EINVAL;
			}
		      return -1;
		    }
		}
	      default:
		errno = ENOSYS;
		return -1;
	    }
	}
      default:
	errno = ENOSYS;
	va_end (ap);
	return -1;
    }
}

static intptr_t mutex_handle = -1;

/* Record in a static variable the mutex handle we were requested to
   use.  That nameless mutex was created by the top-level Make, and
   its handle was passed to us via inheritance.  The value of that
   handle is passed via the command-line arguments, so that we know
   which handle to use.  */
void
record_sync_mutex (const char *str)
{
  char *endp;
  intptr_t hmutex = strtol (str, &endp, 16);

  if (*endp == '\0')
    mutex_handle = hmutex;
  else
    {
      mutex_handle = -1;
      errno = EINVAL;
    }
}

/* Create a new mutex or reuse one created by our parent.  */
intptr_t
create_mutex (void)
{
  SECURITY_ATTRIBUTES secattr;
  intptr_t hmutex = -1;

  /* If we have a mutex handle passed from the parent Make, just use
     that.  */
  if (mutex_handle > 0)
    return mutex_handle;

  /* We are the top-level Make, and we want the handle to be inherited
     by our child processes.  */
  secattr.nLength = sizeof (secattr);
  secattr.lpSecurityDescriptor = NULL; /* use default security descriptor */
  secattr.bInheritHandle = TRUE;

  hmutex = (intptr_t)CreateMutex (&secattr, FALSE, NULL);
  if (!hmutex)
    {
      DWORD err = GetLastError ();

      fprintf (stderr, "CreateMutex: error %lu\n", err);
      errno = ENOLCK;
      hmutex = -1;
    }

  mutex_handle = hmutex;
  return hmutex;
}

/* Return non-zero if F1 and F2 are 2 streams representing the same
   file or pipe or device.  */
int
same_stream (FILE *f1, FILE *f2)
{
  HANDLE fh1 = (HANDLE)_get_osfhandle (fileno (f1));
  HANDLE fh2 = (HANDLE)_get_osfhandle (fileno (f2));

  /* Invalid file descriptors get treated as different streams.  */
  if (fh1 && fh1 != INVALID_HANDLE_VALUE
      && fh2 && fh2 != INVALID_HANDLE_VALUE)
    {
      if (fh1 == fh2)
	return 1;
      else
	{
	  DWORD ftyp1 = GetFileType (fh1), ftyp2 = GetFileType (fh2);

	  if (ftyp1 != ftyp2
	      || ftyp1 == FILE_TYPE_UNKNOWN || ftyp2 == FILE_TYPE_UNKNOWN)
	    return 0;
	  else if (ftyp1 == FILE_TYPE_CHAR)
	    {
	      /* For character devices, check if they both refer to a
		 console.  This loses if both handles refer to the
		 null device (FIXME!), but in that case we don't care
		 in the context of Make.  */
	      DWORD conmode1, conmode2;

	      /* Each process on Windows can have at most 1 console,
		 so if both handles are for the console device, they
		 are the same.  We also compare the console mode to
		 distinguish between tsdin and stdout/stderr.  */
	      if (GetConsoleMode (fh1, &conmode1)
		  && GetConsoleMode (fh2, &conmode2)
		  && conmode1 == conmode2)
		return 1;
	    }
	  else
	    {
	      /* For disk files and pipes, compare their unique
		 attributes.  */
	      BY_HANDLE_FILE_INFORMATION bhfi1, bhfi2;

	      /* Pipes get zero in the volume serial number, but do
		 appear to have meaningful information in file index
		 attributes.  We test file attributes as well, for a
		 good measure.  */
	      if (GetFileInformationByHandle (fh1, &bhfi1)
		  && GetFileInformationByHandle (fh2, &bhfi2))
		return (bhfi1.dwVolumeSerialNumber == bhfi2.dwVolumeSerialNumber
			&& bhfi1.nFileIndexLow == bhfi2.nFileIndexLow
			&& bhfi1.nFileIndexHigh == bhfi2.nFileIndexHigh
			&& bhfi1.dwFileAttributes == bhfi2.dwFileAttributes);
	    }
	}
    }
  return 0;
}

#endif	/* OUTPUT_SYNC */
