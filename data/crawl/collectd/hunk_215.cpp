 {
     lvm_t lvm;
     vg_t vg;
-    struct dm_list *vgnames;
-    struct lvm_str_list *strl;
+    int status = 0;
+    struct dm_list *vg_names;
+    struct lvm_str_list *name_list;
 
     lvm = lvm_init(NULL);
     if (!lvm) {
-        fprintf(stderr, "lvm_init() failed\n");
+    	status = lvm_errno(lvm);
+    	ERROR("volume plugin: lvm_init failed: %s", lvm_errmsg(lvm));
     }
 
-    vgnames = lvm_list_vg_names(lvm);
-    if (!vgnames) {
-        fprintf(stderr, "lvm_list_vg_names() failed\n");
+    vg_names = lvm_list_vg_names(lvm);
+    if (!vg_names) {
+    	status = lvm_errno(lvm);
+    	ERROR("volume plugin lvm_list_vg_name failed %s", lvm_errmsg(lvm));
     }
 
-    dm_list_iterate_items(strl, vgnames) {
-        vg = lvm_vg_open(lvm, strl->str, "r", 0);
-        volume_submit(strl->str, lvm_vg_get_size(vg), lvm_vg_get_free_size(vg));
+    dm_list_iterate_items(name_list, vg_names) {
+        vg = lvm_vg_open(lvm, name_list->str, "r", 0);
+        volume_submit(name_list->str, "df_complex", "size", lvm_vg_get_size(vg));
+        volume_submit(name_list->str, "df_complex", "free", lvm_vg_get_free_size(vg));
+
         lvm_vg_close(vg);
     }
 