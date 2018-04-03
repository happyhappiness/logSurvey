    if (Config.icons.use_short_names) {
        static MemBuf mb;
        mb.reset();
        mb.appendf("/squid-internal-static/icons/%s", icon);
        return mb.content();
    } else {
        return internalLocalUri("/squid-internal-static/icons/", icon);
