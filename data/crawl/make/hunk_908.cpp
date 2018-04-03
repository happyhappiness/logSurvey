       /* If we're substituting only by fully matched words,
 	 or only at the ends of words, check that this case qualifies.  */
       if ((by_word
-	   && ((p > t && !isblank (p[-1]))
-	       || (p[slen] != '\0' && !isblank (p[slen]))))
+	   && ((p > t && !isblank ((unsigned char)p[-1]))
+	       || (p[slen] != '\0' && !isblank ((unsigned char)p[slen]))))
 	  || (suffix_only
-	      && (p[slen] != '\0' && !isblank (p[slen]))))
+	      && (p[slen] != '\0' && !isblank ((unsigned char)p[slen]))))
 	/* Struck out.  Output the rest of the string that is
 	   no longer to be replaced.  */
 	o = variable_buffer_output (o, subst, slen);
