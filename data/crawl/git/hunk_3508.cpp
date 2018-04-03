 
 Performance, Internal Implementation, etc.
 
+ * The function attributes extensions are used to catch mistakes in
+   use of our own variadic functions that use NULL sentinel at the end
+   (i.e. like execl(3)) and format strings (i.e. like printf(3)).
+
+ * The code to allow configuration data to be read from in-tree blob
+   objects is in.  This may help working in a bare repository and
+   submodule updates.
+
  * Fetching between repositories with many refs employed O(n^2)
    algorithm to match up the common objects, which has been corrected.
 
