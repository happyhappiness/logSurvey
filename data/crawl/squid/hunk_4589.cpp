 }
 
 StoreSearch *
-StoreHashIndex::search(string const url, HttpRequest *)
+StoreHashIndex::search(String const url, HttpRequest *)
 {
     if (url.size())
         fatal ("Cannot search by url yet\n");
