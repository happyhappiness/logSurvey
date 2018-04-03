                           ae->name,
                           ae->typeString(),
                           ae->flags.flagsStr());
-        wordlist *w = ae->dump();
-        dump_wordlist(entry, w);
-
-        storeAppendPrintf(entry, "\n");
-        wordlistDestroy(&w);
+        dump_SBufList(entry, ae->dump());
         ae = ae->next;
     }
 }
