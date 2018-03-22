  return (tar_sparse_done (&file) && rc) ? dump_status_ok : dump_status_short;
}

     
/* Old GNU Format. The sparse file information is stored in the
   oldgnu_header in the following manner:
