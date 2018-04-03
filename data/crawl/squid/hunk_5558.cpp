 	mp.allocated);
     fprintf(debug_log, "\tbytes used in maintaining the free tree:\t%d\n",
 	mp.treeoverhead);
-#endif /* HAVE_EXT_MALLINFO */
+#endif /* HAVE_STRUCT_MALLINFO_MXFAST */
 #endif /* HAVE_MALLINFO */
 }
 