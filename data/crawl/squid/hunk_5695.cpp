 	    storeAppendPrintf(s, "\tClient #%d, %p\n", i, sc->callback_data);
 	    storeAppendPrintf(s, "\t\tcopy_offset: %d\n",
 		(int) sc->copy_offset);
-	    storeAppendPrintf(s, "\t\tseen_offset: %d\n",
-		(int) sc->seen_offset);
 	    storeAppendPrintf(s, "\t\tcopy_size: %d\n",
 		(int) sc->copy_size);
 	    storeAppendPrintf(s, "\t\tflags:");
