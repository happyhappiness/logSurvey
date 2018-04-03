        return path.lower().startswith(prefix.lower())
    return path.startswith(prefix)

class Command:
    def __init__(self):
        self.usage = "usage: %prog [options]"
