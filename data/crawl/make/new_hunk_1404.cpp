
	    free (buffer);
	  }
#else	/* Amiga */
	 {
	   /* Amiga can't fork nor spawn, but I can start a program with
	      redirection of my choice.   However, this means that we
	      don't have an opportunity to reopen stdout to trap it.  Thus,
	      we save our own stdout onto a new descriptor and dup a temp
	      file's descriptor onto our stdout temporarily.  After we
	      spawn the shell program, we dup our own stdout back to the
	      stdout descriptor.  The buffer reading is the same as above,
	      except that we're now reading from a file. */
#include <dos/dos.h>
#include <proto/dos.h>

