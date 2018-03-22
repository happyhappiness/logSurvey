	      /* For an unknown encoding, assume ASCII.  */
	      utf8_to_local = iconv_open ("ASCII", UTF8_NAME);
	      if (utf8_to_local == (iconv_t)(-1))
		return failure (code, callback_arg);
	    }
	}
#endif
