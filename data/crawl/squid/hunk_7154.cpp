 	wordlistAdd(list, token);
 }
 
-static void
-parse_proxyauth(void)
-{
-	fatal("not implemented");
-}
-
-static void
-dump_proxyauth(void)
-{
-	fatal("not implemented");
-}
+#define free_wordlist wordlistDestroy
 
 #include "cf_parser.c"
