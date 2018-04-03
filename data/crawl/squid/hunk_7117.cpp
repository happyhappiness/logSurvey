 	/* NOTREACHED */
 	break;
     default:
-	debug_trap("storeGeneratePublicKey: Unsupported request method");
+	fatal_dump("storeGeneratePublicKey: Unsupported request method");
 	break;
     }
     return NULL;
