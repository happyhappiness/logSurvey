     request_set_header (req, "Referer", opt.referer, rel_none);

     // Value freshly allocated, free it when done.
     request_set_header (req, "Range", aprintf ("bytes=%ld-", hs->restval),
			 rel_value);
   */

