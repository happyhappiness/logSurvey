    // versions block responses that use those alternative syntax rules!
    MemBuf mb;
    mb.init();
    mb.appendf("227 Entering Passive Mode (%s,%i,%i).\r\n",
              addr,
              static_cast<int>(localPort / 256),
              static_cast<int>(localPort % 256));
