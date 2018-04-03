  * know the (absolute) path of the file that was created, it can be
  * read from tempfile->filename.
  *
- * On success, the functions return a file descriptor that is open for
- * writing the temporary file. On errors, they return -1 and set errno
- * appropriately (except for the "x" variants, which die() on errors).
+ * On success, the functions return a tempfile whose "fd" member is open
+ * for writing the temporary file. On errors, they return NULL and set
+ * errno appropriately (except for the "x" variants, which die() on
+ * errors).
  */
 
 /* See "mks_tempfile functions" above. */
-extern int mks_tempfile_sm(struct tempfile *tempfile,
-			   const char *template, int suffixlen, int mode);
+extern struct tempfile *mks_tempfile_sm(const char *template,
+					int suffixlen, int mode);
 
 /* See "mks_tempfile functions" above. */
-static inline int mks_tempfile_s(struct tempfile *tempfile,
-				 const char *template, int suffixlen)
+static inline struct tempfile *mks_tempfile_s(const char *template,
+					      int suffixlen)
 {
-	return mks_tempfile_sm(tempfile, template, suffixlen, 0600);
+	return mks_tempfile_sm(template, suffixlen, 0600);
 }
 
 /* See "mks_tempfile functions" above. */
-static inline int mks_tempfile_m(struct tempfile *tempfile,
-				 const char *template, int mode)
+static inline struct tempfile *mks_tempfile_m(const char *template, int mode)
 {
-	return mks_tempfile_sm(tempfile, template, 0, mode);
+	return mks_tempfile_sm(template, 0, mode);
 }
 
 /* See "mks_tempfile functions" above. */
-static inline int mks_tempfile(struct tempfile *tempfile,
-			       const char *template)
+static inline struct tempfile *mks_tempfile(const char *template)
 {
-	return mks_tempfile_sm(tempfile, template, 0, 0600);
+	return mks_tempfile_sm(template, 0, 0600);
 }
 
 /* See "mks_tempfile functions" above. */
-extern int mks_tempfile_tsm(struct tempfile *tempfile,
-			    const char *template, int suffixlen, int mode);
+extern struct tempfile *mks_tempfile_tsm(const char *template,
+					 int suffixlen, int mode);
 
 /* See "mks_tempfile functions" above. */
-static inline int mks_tempfile_ts(struct tempfile *tempfile,
-				  const char *template, int suffixlen)
+static inline struct tempfile *mks_tempfile_ts(const char *template,
+					       int suffixlen)
 {
-	return mks_tempfile_tsm(tempfile, template, suffixlen, 0600);
+	return mks_tempfile_tsm(template, suffixlen, 0600);
 }
 
 /* See "mks_tempfile functions" above. */
-static inline int mks_tempfile_tm(struct tempfile *tempfile,
-				  const char *template, int mode)
+static inline struct tempfile *mks_tempfile_tm(const char *template, int mode)
 {
-	return mks_tempfile_tsm(tempfile, template, 0, mode);
+	return mks_tempfile_tsm(template, 0, mode);
 }
 
 /* See "mks_tempfile functions" above. */
-static inline int mks_tempfile_t(struct tempfile *tempfile,
-				 const char *template)
+static inline struct tempfile *mks_tempfile_t(const char *template)
 {
-	return mks_tempfile_tsm(tempfile, template, 0, 0600);
+	return mks_tempfile_tsm(template, 0, 0600);
 }
 
 /* See "mks_tempfile functions" above. */
-extern int xmks_tempfile_m(struct tempfile *tempfile,
-			   const char *template, int mode);
+extern struct tempfile *xmks_tempfile_m(const char *template, int mode);
 
 /* See "mks_tempfile functions" above. */
-static inline int xmks_tempfile(struct tempfile *tempfile,
-				const char *template)
+static inline struct tempfile *xmks_tempfile(const char *template)
 {
-	return xmks_tempfile_m(tempfile, template, 0600);
+	return xmks_tempfile_m(template, 0600);
 }
 
 /*
