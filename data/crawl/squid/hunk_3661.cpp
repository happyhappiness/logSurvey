 #endif /* IF !DEF CYGWIN */
 	fp = fopen("conftestval", "w");
 	fprintf (fp, "%d\n", i & ~0x3F);
-	exit(0);
+	return 0;
 }
-  ],
-  SQUID_MAXFD=`cat conftestval`,
-  SQUID_MAXFD=256,
-  SQUID_MAXFD=256)
+  ]])],[SQUID_MAXFD=`cat conftestval`],[SQUID_MAXFD=256],[SQUID_MAXFD=256])
   dnl Microsoft MSVCRT.DLL supports 2048 maximum FDs
   case "$host_os" in
   mingw|mingw32)
