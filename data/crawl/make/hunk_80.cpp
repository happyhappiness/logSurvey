 } sub_process;
 
 /* keep track of children so we can implement a waitpid-like routine */
-static sub_process *proc_array[MAXIMUM_WAIT_OBJECTS];
+static sub_process *proc_array[GMAKE_MAXIMUM_WAIT_OBJECTS];
 static int proc_index = 0;
 static int fake_exits_pending = 0;
 
+/*
+ * Address the scalability limit intrisic to WaitForMultipleOjects by
+ * calling WaitForMultipleObjects on 64 element chunks of the input
+ * array with 0 timeout.  Exit with an appropriately conditioned result
+ * or repeat again every 10 ms if no handle has signaled and the
+ * requested timeout was not zero.
+ */
+DWORD process_wait_for_multiple_objects(
+  DWORD nCount,
+  const HANDLE *lpHandles,
+  BOOL bWaitAll,
+  DWORD dwMilliseconds
+)
+{
+  assert(nCount <= GMAKE_MAXIMUM_WAIT_OBJECTS);
+
+  if (nCount <= MAXIMUM_WAIT_OBJECTS) {
+    DWORD retVal =  WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds);
+    return (retVal == WAIT_TIMEOUT) ? GMAKE_WAIT_TIMEOUT : retVal;
+  } else {
+    for (;;) {
+      DWORD objectCount = nCount;
+      int blockCount  = 0;
+      DWORD retVal;
+
+      assert(bWaitAll == FALSE); /* This logic only works for this use case */
+      assert(dwMilliseconds == 0 || dwMilliseconds == INFINITE); /* No support for timeouts */
+
+      for (; objectCount > 0; blockCount++) {
+	DWORD n = objectCount <= MAXIMUM_WAIT_OBJECTS ? objectCount : MAXIMUM_WAIT_OBJECTS;
+	objectCount -= n;
+	retVal = WaitForMultipleObjects(n, &lpHandles[blockCount * MAXIMUM_WAIT_OBJECTS],
+					    FALSE, 0);
+	switch (retVal) {
+	  case WAIT_TIMEOUT:
+	    retVal = GMAKE_WAIT_TIMEOUT;
+	    continue;
+	    break;
+	  case WAIT_FAILED:
+	    fprintf(stderr,"WaitForMultipleOjbects failed waiting with error %d\n", GetLastError());
+	    break;
+	  default:
+	    if (retVal >= WAIT_ABANDONED_0) {
+	      assert(retVal < WAIT_ABANDONED_0 + MAXIMUM_WAIT_OBJECTS);
+	      retVal += blockCount * MAXIMUM_WAIT_OBJECTS - WAIT_ABANDONED_0 + GMAKE_WAIT_ABANDONED_0;
+	    } else {
+	      assert(retVal < WAIT_OBJECT_0 + MAXIMUM_WAIT_OBJECTS);
+	      retVal += blockCount * MAXIMUM_WAIT_OBJECTS;
+	    }
+	    break;
+	}
+
+	return retVal;
+
+      }
+
+      if (dwMilliseconds == 0) return retVal;
+
+      Sleep(10);  /* Sleep for 10 ms */
+    }
+  }
+}
 
 /*
  * Fill a HANDLE list with handles to wait for.
