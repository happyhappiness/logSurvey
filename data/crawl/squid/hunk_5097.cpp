         alarm(1);
         memset(&rmsg, '\0', sizeof(rmsg));
         DEBUG(2)
-        fprintf(stderr, "msgrcv: %ld, %p, %u, %ld, %d \n",
-                rmsgid, &rmsg, diomsg::msg_snd_rcv_sz, 0, 0);
+        std::cerr << "msgrcv: " << rmsgid << ", "
+        << &rmsg << ", " << diomsg::msg_snd_rcv_sz
+        << ", " << 0 << ", " << 0 << std::endl;
         rlen = msgrcv(rmsgid, &rmsg, diomsg::msg_snd_rcv_sz, 0, 0);
 
         if (rlen < 0) {