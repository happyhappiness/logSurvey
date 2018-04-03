        return;

    if (!entry->isEmpty()) { // too late to block (should not really happen)
       if (request)
           request->detailError(ERR_ICAP_FAILURE, ERR_DETAIL_RESPMOD_BLOCK_LATE);
       abortTransaction("late adaptation block");
       return;
    }
      
    debugs(11,7, HERE << "creating adaptation block response");

    err_type page_id =
