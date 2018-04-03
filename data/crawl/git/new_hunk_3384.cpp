                # assume error is "... file(s) not in client view"
                continue
            if "clientFile" not in res:
                die("No clientFile in 'p4 where' output")
            if "unmap" in res:
                # it will list all of them, but only one not unmap-ped
                continue