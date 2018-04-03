                       &child->pid, &child->cstatus, &child->efn,
                       vmsHandleChildTerm, child,
                       0, 0, 0);
+   status = child->vms_launch_status;
 #endif
 
-  if (!(status & 1))
+  if (!$VMS_STATUS_SUCCESS (status))
     {
-      printf (_("Error spawning, %d\n") ,status);
-      fflush (stdout);
       switch (status)
         {
-        case 0x1c:
+        case SS$_EXQUOTA:
           errno = EPROCLIM;
           break;
         default:
