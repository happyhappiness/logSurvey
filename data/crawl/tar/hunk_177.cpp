 	case GNUTYPE_LONGNAME:
 	case GNUTYPE_LONGLINK:
 	  modes[0] = 'L';
-	  ERROR ((0, 0, _("Visible longname error")));
+	  ERROR ((0, 0, _("Unexpected long name header")));
 	  break;
 
 	case GNUTYPE_SPARSE:
