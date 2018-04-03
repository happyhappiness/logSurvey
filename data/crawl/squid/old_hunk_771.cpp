    MemBuf mb;
    mb.init();
    if (sendDetails) {
        mb.Printf("%i-%s\r\n", code, msg);
        mb.Printf(" Server reply:\r\n");
        Ftp::PrintReply(mb, reply, " ");
        mb.Printf("%i \r\n", code);
    } else
        mb.Printf("%i %s\r\n", code, msg);

    writeReply(mb);
}
