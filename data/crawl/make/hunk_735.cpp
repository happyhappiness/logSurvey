                       TRUE,
                       DUPLICATE_SAME_ACCESS) == FALSE) {
     fprintf(stderr,
-           "process_easy: DuplicateHandle(Out) failed (e=%d)\n",
+           "process_easy: DuplicateHandle(Out) failed (e=%ld)\n",
            GetLastError());
     return INVALID_HANDLE_VALUE;
   }
