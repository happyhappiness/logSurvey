 extern void logfilePrintf(va_alist);
 #endif
 
-/* Removal Policies */
-RemovalPolicy *
-createRemovalPolicy(RemovalPolicySettings *settings);
+/*
+ * Removal Policies
+ */
+extern RemovalPolicy *createRemovalPolicy(RemovalPolicySettings * settings);
 
 /*
  * prototypes for system functions missing from system includes
