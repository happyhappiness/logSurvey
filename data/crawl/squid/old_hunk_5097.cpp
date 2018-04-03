        alarm(1);
        memset(&rmsg, '\0', sizeof(rmsg));
        DEBUG(2)
        fprintf(stderr, "msgrcv: %ld, %p, %u, %ld, %d \n",
                rmsgid, &rmsg, diomsg::msg_snd_rcv_sz, 0, 0);
        rlen = msgrcv(rmsgid, &rmsg, diomsg::msg_snd_rcv_sz, 0, 0);

        if (rlen < 0) {