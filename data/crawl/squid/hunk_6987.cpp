 {
     switch (var) {
     case ANONYMIZER_NONE:
-	printf("off");
+	storeAppendPrintf(entry, "%s off\n", name);
 	break;
     case ANONYMIZER_STANDARD:
-	printf("paranoid");
+	storeAppendPrintf(entry, "%s paranoid\n", name);
 	break;
     case ANONYMIZER_PARANOID:
-	printf("standard");
+	storeAppendPrintf(entry, "%s standard\n", name);
 	break;
     }
 }
