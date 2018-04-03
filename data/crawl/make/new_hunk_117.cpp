                      &child->pid, &child->cstatus, &child->efn,
                      vmsHandleChildTerm, child,
                      0, 0, 0);
   status = child->vms_launch_status;
#endif

  if (!$VMS_STATUS_SUCCESS (status))
    {
      switch (status)
        {
        case SS$_EXQUOTA:
          errno = EPROCLIM;
          break;
        default:
