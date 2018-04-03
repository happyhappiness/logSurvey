            os.makedirs(remotePath)
        shutil.copyfile(localLargeFile, os.path.join(remotePath, os.path.basename(localLargeFile)))

class Command:
    def __init__(self):
        self.usage = "usage: %prog [options]"
