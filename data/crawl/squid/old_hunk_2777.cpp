        map = new DirMap(path, eAllowed);
    }

    DiskIOModule *m = DiskIOModule::Find("IpcIo"); // TODO: configurable?
    assert(m);
    io = m->createStrategy();
    io->init();

    theFile = io->newFile(filePath);
    theFile->open(O_RDWR, 0644, this);