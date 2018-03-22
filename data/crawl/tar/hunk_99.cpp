       *fun = extract_volhdr;
       break;
 
-    case GNUTYPE_NAMES:
-      *fun = extract_mangle_wrapper;
-      break;
-
     case GNUTYPE_MULTIVOL:
       ERROR ((0, 0,
 	      _("%s: Cannot extract -- file is continued from another volume"),
