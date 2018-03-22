 #include "common.h"
 
 #include "backupfile.h"
-enum backup_type get_version ();
-
-/* FIXME: We should use a conversion routine that does reasonable error
-   checking -- atol doesn't.  For now, punt.  */
-#define intconv	atol
+#include "xstrtol.h"
 
 time_t get_date ();
 
