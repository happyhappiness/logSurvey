 }
 
 StoreSearch *
-UFSSwapDir::search(string const url, HttpRequest *request)
+UFSSwapDir::search(String const url, HttpRequest *request)
 {
     if (url.size())
         fatal ("Cannot search by url yet\n");
