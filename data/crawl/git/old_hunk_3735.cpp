    else:
        local_path = os.path.join(dirname, 'clone')
        if not os.path.exists(local_path):
            peer, dstpeer = hg.clone(myui, {}, url, local_path, update=False, pull=True)
            repo = dstpeer.local()
        else:
            repo = hg.repository(myui, local_path)
            peer = hg.peer(myui, {}, url)
            repo.pull(peer, heads=None, force=True)

    return repo