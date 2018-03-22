 	    break;
 
 	  default:
-	    ERROR ((0, 0, _("This does not look like a tar archive")));
+	    WARN ((0, 0, _("This does not look like a tar archive")));
 	    return false;
 	  }
         break;
