	  || (res > 0 && code != 0 && outptr - outbuf == 1 && *outbuf == '\0')
# endif
         )
	error (1, res == (size_t)(-1) ? errno : 0,
	       _("cannot convert U+%04X to local character set"), code);

      /* Avoid glibc-2.1 bug and Solaris 2.7 bug.  */
# if defined _LIBICONV_VERSION \
