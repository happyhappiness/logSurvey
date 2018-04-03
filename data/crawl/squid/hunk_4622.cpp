 }
 
 StoreSearch *
-StoreHashIndex::search(String const url, HttpRequest *)
+StoreHashIndex::search(string const url, HttpRequest *)
 {
     if (url.size())
         fatal ("Cannot search by url yet\n");
