 	      /* For an unknown encoding, assume ASCII.  */
 	      utf8_to_local = iconv_open ("ASCII", UTF8_NAME);
 	      if (utf8_to_local == (iconv_t)(-1))
-		error (1, 0,
-		       _("cannot convert U+%04X to local character set: iconv function not usable"),
-		       code);
+		return failure (code, callback_arg);
 	    }
 	}
 #endif
