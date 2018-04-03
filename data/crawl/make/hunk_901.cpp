 # define va_alist a1, a2, a3, a4, a5, a6, a7, a8
 # define va_dcl char *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
 # define VA_START(args, lastarg)
+# define VA_PRINTF(fp, lastarg, args) fprintf((fp), (lastarg), va_alist)
 # define VA_END(args)
 #endif
 
