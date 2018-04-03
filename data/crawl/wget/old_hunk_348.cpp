        }
      else if (opt.noclobber || opt.always_rest || opt.timestamping || opt.dirstruct
               || opt.output_document)
        {
#ifdef __VMS
          int open_id;

