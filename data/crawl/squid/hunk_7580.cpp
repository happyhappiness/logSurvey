 	/* NOTREACHED */
 	break;
     default:
-	fatal_dump("storeGeneratePublicKey: Unsupported request method");
+	debug_trap("storeGeneratePublicKey: Unsupported request method");
 	break;
     }
     return NULL;
