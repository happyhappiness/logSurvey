               p += 5;
               remove_comments (p);
               if (*(next_token (p)) != '\0')
-                error (&ebuf->floc,
-                       _("extraneous text after 'endef' directive"));
+                O (error, &ebuf->floc,
+                   _("extraneous text after 'endef' directive"));
 
               if (--nlevels == 0)
                 break;
