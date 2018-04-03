 def originP4BranchesExist():
         return gitBranchExists("origin") or gitBranchExists("origin/p4") or gitBranchExists("origin/p4/master")
 
-def p4ChangesForPaths(depotPaths, changeRange, block_size):
+
+def p4ParseNumericChangeRange(parts):
+    changeStart = int(parts[0][1:])
+    if parts[1] == '#head':
+        changeEnd = p4_last_change()
+    else:
+        changeEnd = int(parts[1])
+
+    return (changeStart, changeEnd)
+
+def chooseBlockSize(blockSize):
+    if blockSize:
+        return blockSize
+    else:
+        return defaultBlockSize
+
+def p4ChangesForPaths(depotPaths, changeRange, requestedBlockSize):
     assert depotPaths
-    assert block_size
 
-    # Parse the change range into start and end
+    # Parse the change range into start and end. Try to find integer
+    # revision ranges as these can be broken up into blocks to avoid
+    # hitting server-side limits (maxrows, maxscanresults). But if
+    # that doesn't work, fall back to using the raw revision specifier
+    # strings, without using block mode.
+
     if changeRange is None or changeRange == '':
-        changeStart = '@1'
-        changeEnd = '#head'
+        changeStart = 1
+        changeEnd = p4_last_change()
+        block_size = chooseBlockSize(requestedBlockSize)
     else:
         parts = changeRange.split(',')
         assert len(parts) == 2
-        changeStart = parts[0]
-        changeEnd = parts[1]
+        try:
+            (changeStart, changeEnd) = p4ParseNumericChangeRange(parts)
+            block_size = chooseBlockSize(requestedBlockSize)
+        except:
+            changeStart = parts[0][1:]
+            changeEnd = parts[1]
+            if requestedBlockSize:
+                die("cannot use --changes-block-size with non-numeric revisions")
+            block_size = None
 
     # Accumulate change numbers in a dictionary to avoid duplicates
     changes = {}
 
     for p in depotPaths:
         # Retrieve changes a block at a time, to prevent running
-        # into a MaxScanRows error from the server.
-        start = changeStart
-        end = changeEnd
-        get_another_block = True
-        while get_another_block:
-            new_changes = []
+        # into a MaxResults/MaxScanRows error from the server.
+
+        while True:
             cmd = ['changes']
-            cmd += ['-m', str(block_size)]
-            cmd += ["%s...%s,%s" % (p, start, end)]
+
+            if block_size:
+                end = min(changeEnd, changeStart + block_size)
+                revisionRange = "%d,%d" % (changeStart, end)
+            else:
+                revisionRange = "%s,%s" % (changeStart, changeEnd)
+
+            cmd += ["%s...@%s" % (p, revisionRange)]
+
             for line in p4_read_pipe_lines(cmd):
                 changeNum = int(line.split(" ")[1])
-                new_changes.append(changeNum)
                 changes[changeNum] = True
-            if len(new_changes) == block_size:
-                get_another_block = True
-                end = '@' + str(min(new_changes))
-            else:
-                get_another_block = False
+
+            if not block_size:
+                break
+
+            if end >= changeEnd:
+                break
+
+            changeStart = end + 1
 
     changelist = changes.keys()
     changelist.sort()
