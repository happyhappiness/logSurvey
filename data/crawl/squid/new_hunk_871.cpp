        const String info = ah->allMeta.getByName("X-Response-Info");
        const String desc = ah->allMeta.getByName("X-Response-Desc");
        if (info.size())
            mb.appendf("%i-Information: %s\r\n", scode, info.termedBuf());
        if (desc.size())
            mb.appendf("%i-Description: %s\r\n", scode, desc.termedBuf());
    }
#endif

