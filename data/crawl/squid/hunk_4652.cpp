     entry = gopherState->entry;
 
     if (gopherState->conversion == gopher_ds::HTML_INDEX_PAGE) {
-        char *html_url = html_quote(storeUrl(entry));
+        char *html_url = html_quote(entry->url());
         gopherHTMLHeader(entry, "Gopher Index %s", html_url);
         storeAppendPrintf(entry,
                           "<p>This is a searchable Gopher index. Use the search\n"
                           "function of your browser to enter search terms.\n"
                           "<ISINDEX>\n");
         gopherHTMLFooter(entry);
         /* now let start sending stuff to client */
-        storeBufferFlush(entry);
+        entry->flush();
         gopherState->HTML_header_added = 1;
 
         return;
     }
 
     if (gopherState->conversion == gopher_ds::HTML_CSO_PAGE) {
-        char *html_url = html_quote(storeUrl(entry));
+        char *html_url = html_quote(entry->url());
         gopherHTMLHeader(entry, "CSO Search of %s", html_url);
         storeAppendPrintf(entry,
                           "<P>A CSO database usually contains a phonebook or\n"
                           "directory.  Use the search function of your browser to enter\n"
                           "search terms.</P><ISINDEX>\n");
         gopherHTMLFooter(entry);
         /* now let start sending stuff to client */
-        storeBufferFlush(entry);
+        entry->flush();
         gopherState->HTML_header_added = 1;
 
         return;
