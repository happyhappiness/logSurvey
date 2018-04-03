 
               wtype = get_next_mword(lb_next, NULL, &lb_next, &len);
               if (wtype == w_eol)
-                /* There's no need to be ivory-tower about this: check for
-                   one of the most common bugs found in makefiles...  */
-                fatal (&fileinfo, "missing separator%s",
-                       strncmp(lb.buffer, "        ", 8) ? ""
-                       : " (did you mean TAB instead of 8 spaces?)");
+                break;
 
               p2 += strlen(p2);
               *(p2++) = ' ';
