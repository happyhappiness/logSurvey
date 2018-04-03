 {
     dread_ctrl *ctrl_dat;
     if (fd < 0)
-       fatal_dump("file_read: bad FD");
+	fatal_dump("file_read: bad FD");
     ctrl_dat = xcalloc(1, sizeof(dread_ctrl));
     ctrl_dat->fd = fd;
     ctrl_dat->offset = offset;
