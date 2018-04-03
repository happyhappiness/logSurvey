    MemBuf mb;
    mb.init();
    if (sendDetails) {
        mb.appendf("%i-%s\r\n", code, msg);
        mb.appendf(" Server reply:\r\n");
        Ftp::PrintReply(mb, reply, " ");
        mb.appendf("%i \r\n", code);
    } else
        mb.appendf("%i %s\r\n", code, msg);

    writeReply(mb);
}
