                # assume error is "... file(s) not in client view"
                continue
            if "clientFile" not in res:
                die("No clientFile from 'p4 where %s'" % depot_path)
            if "unmap" in res:
                # it will list all of them, but only one not unmap-ped
                continue