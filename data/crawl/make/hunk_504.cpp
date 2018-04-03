 
       /* If there is nothing left to be eval'd, there's no 'endef'!!  */
       if (nlines < 0)
-        fatal (&defstart, _("missing `endef', unterminated `define'"));
+        fatal (&defstart, _("missing 'endef', unterminated 'define'"));
 
       ebuf->floc.lineno += nlines;
       line = ebuf->buffer;
