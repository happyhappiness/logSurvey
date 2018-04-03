 
         Mem::Init();
 
-        setMaxFD();
-
-        comm_init(); /* initialize early to handle fatal() errors */
-
         storeFsInit();		/* required for config parsing */
 
         /* May not be needed for parsing, have not audited for such */
