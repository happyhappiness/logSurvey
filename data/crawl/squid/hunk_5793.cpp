 	/* people might want a zero-sized cache on purpose */
 	(void) 0;
     else if (Config.Swap.maxSize < (Config.memMaxSize >> 10))
-	fatal("cache_swap is lower than cache_mem");
+	debug(3, 0) ("WARNING cache_mem is larger than total disk cache space!\n");
     if (Config.Announce.period > 0) {
 	Config.onoff.announce = 1;
     } else if (Config.Announce.period < 1) {