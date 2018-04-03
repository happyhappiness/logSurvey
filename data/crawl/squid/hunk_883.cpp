                    SQUIDSTRINGPRINT(urlpath_or_slash),
                    AnyP::ProtocolType_str[request->http_ver.protocol],
                    request->http_ver.major, request->http_ver.minor);
-        packerToMemInit(&pck, &str);
-        request->header.packInto(&pck);
+        request->header.packInto(&str);
     }
 
     str.Printf("\r\n");
