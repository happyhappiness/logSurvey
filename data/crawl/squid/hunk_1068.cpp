 }
 
 StoreSearch *
-Fs::Ufs::UFSSwapDir::search(String const url, HttpRequest *request)
+Fs::Ufs::UFSSwapDir::search(String const url, HttpRequest *)
 {
     if (url.size())
         fatal ("Cannot search by url yet\n");