                 if (arg)
                     storeAppendPrintf(entry, "{%s}", arg);
 
-                for (struct TokenTableEntry *te = TokenTable; te->config != NULL; te++) {
-                    if (te->token_type == type) {
-                        storeAppendPrintf(entry, "%s", te->config);
-                        break;
-                    }
-                }
+                storeAppendPrintf(entry, "%s", t->label);
 
                 if (t->space)
                     entry->append(" ", 1);
