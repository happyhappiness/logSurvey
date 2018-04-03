    else:
        local_path = os.path.join(dirname, 'clone')
        if not os.path.exists(local_path):
            try:
                peer, dstpeer = hg.clone(myui, {}, url, local_path, update=True, pull=True)
            except:
                die('Repository error')
            repo = dstpeer.local()
        else:
            repo = hg.repository(myui, local_path)
            try:
                peer = hg.peer(myui, {}, url)
            except:
                die('Repository error')
            repo.pull(peer, heads=None, force=True)

    return repo