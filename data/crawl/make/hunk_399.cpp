           len -= b;
           msg += b;
         }
+      EINTRLOOP (b, write (fd, "\n", 1));
     }
   else
     {
       FILE *f = out ? stdout : stderr;
       fputs (msg, f);
       fflush (f);
+      putc ('\n', f);
     }
 }
 
