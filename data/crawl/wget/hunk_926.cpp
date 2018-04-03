       if (!mcharset)
         return;
 
-      /*logprintf (LOG_VERBOSE, "Meta tag charset : %s\n", quote (mcharset));*/
       xfree_null (meta_charset);
       meta_charset = mcharset;
     }
