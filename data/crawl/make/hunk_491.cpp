               db_level |= DB_BASIC | DB_VERBOSE;
               break;
             default:
-              fatal (NILF, _("unknown debug level specification `%s'"), p);
+              fatal (NILF, _("unknown debug level specification '%s'"), p);
             }
 
           while (*(++p) != '\0')
