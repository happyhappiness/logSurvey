	  || (res > 0 && code != 0 && outptr - outbuf == 1 && *outbuf == '\0')
# endif
         )
	{
	  if (res != (size_t)(-1))
	    errno = EILSEQ;
	  return failure (code, callback_arg);
	}

      /* Avoid glibc-2.1 bug and Solaris 2.7 bug.  */
# if defined _LIBICONV_VERSION \
