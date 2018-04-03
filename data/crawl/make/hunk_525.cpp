 				NULL);
 			FreeLibrary(hModule);
 		}
+#else
+		fatal(NILF, szMessageBuffer);
+#endif
 	} else {
 		/*
 		 *  Default system message handling
