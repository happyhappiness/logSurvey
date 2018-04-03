        revision = ""
        self.users = {}

        newPaths = []
        for p in self.depotPaths:
            if p.find("@") != -1:
