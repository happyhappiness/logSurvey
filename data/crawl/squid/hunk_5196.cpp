 
 /* Matching routines.  */
 
-#ifndef emacs			/* Emacs never uses this.  */
-/* re_match is like re_match_2 except it takes only a single string.  */
-
-int
-re_match(bufp, string, size, pos, regs)
-     struct re_pattern_buffer *bufp;
-     const char *string;
-     int size, pos;
-     struct re_registers *regs;
-{
-    return re_match_2(bufp, NULL, 0, string, size, pos, regs, size);
-}
-#endif /* not emacs */
-
-
 /* re_match_2 matches the compiled pattern in BUFP against the
  * the (virtual) concatenation of STRING1 and STRING2 (of length SIZE1
  * and SIZE2, respectively).  We start matching at POS, and stop
