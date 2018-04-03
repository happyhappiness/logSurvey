  \par
  * "read" handler to accept FTP data connections.
  *
- \param fd	Handle/FD for the listening connection which has received a connect request.
- \param details	Some state data for the listening connection
- \param newfd	Handle/FD to the connection which has just been opened.
- \param flag	Error details for the listening connection. 
- \param xerrno	??
- \param data	??
+ \param io comm accept(2) callback parameters
  */
-static void
-ftpAcceptDataConnection(int fd, int newfd, ConnectionDetail *details,
-                        comm_err_t flag, int xerrno, void *data)
+void FtpStateData::ftpAcceptDataConnection(const CommAcceptCbParams &io)
 {
     char ntoapeer[MAX_IPSTRLEN];
-    FtpStateData *ftpState = (FtpStateData *)data;
-    debugs(9, 3, HERE);
+    debugs(9, 3, "ftpAcceptDataConnection");
 
-    if (flag == COMM_ERR_CLOSING)
+    if (io.flag == COMM_ERR_CLOSING)
         return;
 
-    if (EBIT_TEST(ftpState->entry->flags, ENTRY_ABORTED)) {
-        ftpState->abortTransaction("entry aborted when accepting data conn");
+    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
+        abortTransaction("entry aborted when accepting data conn");
         return;
     }
 
