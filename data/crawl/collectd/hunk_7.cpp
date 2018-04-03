   CHECK_NOT_NULL(l = latency_counter_create());
 
   for (size_t i = 0; i < STATIC_ARRAY_SIZE(cases); i++) {
-    printf("# case %zu: DOUBLE_TO_CDTIME_T(%g) = %" PRIu64 "\n", i,
+    printf("# case %" PRIsz ": DOUBLE_TO_CDTIME_T(%g) = %" PRIu64 "\n", i,
            cases[i].val, DOUBLE_TO_CDTIME_T(cases[i].val));
     latency_counter_add(l, DOUBLE_TO_CDTIME_T(cases[i].val));
 
