 
 Performance, Internal Implementation, etc.
 
+ * When parsing a 40-hex string into the object name, the string is
+   checked to see if it can be interpreted as a ref so that a warning
+   can be given for ambiguity. The code kicked in even when the
+   core.warnambiguousrefs is set to false to squelch this warning, in
+   which case the cycles spent to look at the ref namespace were an
+   expensive no-op, as the result was discarded without being used.
+
  * The naming convention of the packfiles has been updated; it used to
    be based on the enumeration of names of the objects that are
    contained in the pack, but now it also depends on how the packed
