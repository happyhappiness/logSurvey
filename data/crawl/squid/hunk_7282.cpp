     }
 
     /* Sanity checks */
-    if (Config.lifetimeDefault < Config.readTimeout) {
-	printf("WARNING: client_lifetime (%d seconds) is less than read_timeout (%d seconds).\n",
-	    Config.lifetimeDefault, Config.readTimeout);
-	printf("         This may cause serious problems with your cache!!!\n");
-	printf("         Change your configuration file.\n");
-	fflush(stdout);		/* print message */
-    }
     if (Config.Swap.maxSize < (Config.Mem.maxSize >> 10)) {
 	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", Config.Swap.maxSize, Config.Mem.maxSize);
 	printf("         This will cause serious problems with your cache!!!\n");
