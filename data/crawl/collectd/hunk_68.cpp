   return 0;
 }
 
+DEF_TEST (rate) {
+  size_t i;
+  latency_counter_t *l;
+
+  CHECK_NOT_NULL (l = latency_counter_create ());
+
+  for (i = 0; i < 125; i++) {
+    latency_counter_add (l, TIME_T_TO_CDTIME_T (((time_t) i) + 1));
+  }
+  //Test expects bin width equal to 0.125s
+
+  EXPECT_EQ_DOUBLE (1/125, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(10),
+      DOUBLE_TO_CDTIME_T(10),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  EXPECT_EQ_DOUBLE (0, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(10.001),
+      DOUBLE_TO_CDTIME_T(10.125),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  EXPECT_EQ_DOUBLE (1/125, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(10.001),
+      DOUBLE_TO_CDTIME_T(10.876),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  EXPECT_EQ_DOUBLE (2/125, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(10.000),
+      DOUBLE_TO_CDTIME_T(10.876),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  //Range
+  EXPECT_EQ_DOUBLE (10.000 + 1.000/125, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(10),
+      DOUBLE_TO_CDTIME_T(20),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  //Range w/o interpolations
+  EXPECT_EQ_DOUBLE (100, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(0.001),
+      DOUBLE_TO_CDTIME_T(100.0),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  //Full range
+  EXPECT_EQ_DOUBLE (125.0, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(0.001),
+      0,
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  //Overflow test
+  EXPECT_EQ_DOUBLE (125.0, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(0.001),
+      DOUBLE_TO_CDTIME_T(100000),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+
+  //Split range to two parts
+  EXPECT_EQ_DOUBLE (92.0, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(0.001),
+      DOUBLE_TO_CDTIME_T(92.00),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  EXPECT_EQ_DOUBLE (8, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(92.001),
+      DOUBLE_TO_CDTIME_T(100.00),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+
+  //Sum of rates for latencies [0.876, 1.000]
+  EXPECT_EQ_DOUBLE (1, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(0.876),
+      DOUBLE_TO_CDTIME_T(1.000),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+  double sum = 0;
+  for (i = 875 ; i < 1000 ; i += 5) {
+    sum += latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T((double)(i+1)/1000),
+      DOUBLE_TO_CDTIME_T((double)(i+5)/1000),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    );
+    printf("b: %.15g\n",sum);
+  };
+  EXPECT_EQ_DOUBLE (1.000, sum);
+
+  EXPECT_EQ_DOUBLE (100/125, latency_counter_get_rate (l,
+      DOUBLE_TO_CDTIME_T(99.875),
+      DOUBLE_TO_CDTIME_T(99.975),
+      latency_counter_get_start_time(l) + TIME_T_TO_CDTIME_T(1)
+    )
+  );
+
+  latency_counter_destroy (l);
+  return 0;
+}
+
 int main (void)
 {
   RUN_TEST(simple);
   RUN_TEST(percentile);
+  RUN_TEST(rate);
 
   END_TEST;
 }