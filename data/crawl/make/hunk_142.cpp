 			FreeLibrary(hModule);
 		}
 #else
-		fatal(NILF, szMessageBuffer);
+                O (fatal, NILF, szMessageBuffer);
 #endif
 	} else {
 		/*
