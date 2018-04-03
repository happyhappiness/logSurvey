 	}
 	if (use_sideband)
 		packet_flush(1);
-
-	gettimeofday(&tv, NULL);
-	tv.tv_sec -= start_tv.tv_sec;
-	if (tv.tv_usec < start_tv.tv_usec) {
-		tv.tv_sec--;
-		tv.tv_usec += 1000000;
-	}
-	tv.tv_usec -= start_tv.tv_usec;
-	if (run_post_upload_pack_hook(total_sz, &tv))
-		warning("post-upload-hook failed");
 	return;
 
  fail: