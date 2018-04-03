         return;
 
     default:
-        fatal("Hit unreachable code in Http::StreamContext::writeComplete\n");
+        fatal("Hit unreachable code in Http::Stream::writeComplete\n");
     }
 }
 
 void
-Http::StreamContext::pullData()
+Http::Stream::pullData()
 {
     debugs(33, 5, reply << " written " << http->out.size << " into " << clientConnection);
 
