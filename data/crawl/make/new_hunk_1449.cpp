	     }
	   free (buffer);
	 }
#else /* Amiga */
	 {
	   /* Amiga can't fork nor spawn, but I can start a program with
	      redirection of my choice. The rest is the same as above. */
#include <dos/dos.h>
#include <proto/dos.h>

	   BPTR child_stdout;
	   char tmp_output[FILENAME_MAX];
	   unsigned int maxlen = 200;
	   int cc;
	   char * buffer, * ptr;
	   char ** aptr;
	   int len = 0;

	   strcpy (tmp_output, "t:MakeshXXXXXXXX");
	   mktemp (tmp_output);
	   child_stdout = Open (tmp_output, MODE_NEWFILE);

	   for (aptr=argv; *aptr; aptr++)
	     {
	       len += strlen (*aptr) + 1;
	     }

	   buffer = xmalloc (len + 1);
	   ptr = buffer;

	   for (aptr=argv; *aptr; aptr++)
	     {
	       strcpy (ptr, *aptr);
	       len += strlen (ptr) + 1;
	       *ptr ++ = ' ';
	       *ptr = 0;
	     }

	   ptr[-1] = '\n';

	   Execute (buffer, NULL, child_stdout);
	   free (buffer);

	   Close (child_stdout);

	   child_stdout = Open (tmp_output, MODE_OLDFILE);

	   buffer = xmalloc (maxlen);
	   i = 0;
	   do
	     {
	       if (i == maxlen)
		 {
		   maxlen += 512;
		   buffer = (char *) xrealloc (buffer, maxlen + 1);
		 }

	       cc = read (child_stdout, &buffer[i], maxlen - i);
	       if (cc > 0)
		 i += cc;
	     } while (cc > 0);

	   Close (child_stdout);
	   DeleteFile (tmp_output);

	   if (i > 0)
	     {
	       if (buffer[i - 1] == '\n')
		 buffer[--i] = '\0';
	       else
		 buffer[i] = '\0';
	       p = buffer;
	       while ((p = index (p, '\n')) != 0)
		 *p++ = ' ';
	       o = variable_buffer_output (o, buffer, i);
	     }
	   free (buffer);
	 }
#endif	/* Not Amiga.  */
#endif	/* MSDOS or Amiga.  */

	free (text);
	break;
