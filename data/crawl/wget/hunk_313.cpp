             logputs (LOG_VERBOSE, "\n");
         }
     }
-  xfree_null (type);
-  type = NULL;                        /* We don't need it any more.  */
 
   /* Return if we have no intention of further downloading.  */
   if ((!(*dt & RETROKF) && !opt.content_on_error) || head_only)
