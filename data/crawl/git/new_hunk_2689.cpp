            os.makedirs(remotePath)
        shutil.copyfile(localLargeFile, os.path.join(remotePath, os.path.basename(localLargeFile)))

class GitLFS(LargeFileSystem):
    """Git LFS as backend for the git-p4 large file system.
       See https://git-lfs.github.com/ for details."""

    def __init__(self, *args):
        LargeFileSystem.__init__(self, *args)
        self.baseGitAttributes = []

    def generatePointer(self, contentFile):
        """Generate a Git LFS pointer for the content. Return LFS Pointer file
           mode and content which is stored in the Git repository instead of
           the actual content. Return also the new location of the actual
           content.
           """
        pointerProcess = subprocess.Popen(
            ['git', 'lfs', 'pointer', '--file=' + contentFile],
            stdout=subprocess.PIPE
        )
        pointerFile = pointerProcess.stdout.read()
        if pointerProcess.wait():
            os.remove(contentFile)
            die('git-lfs pointer command failed. Did you install the extension?')
        pointerContents = [i+'\n' for i in pointerFile.split('\n')[2:][:-1]]
        oid = pointerContents[1].split(' ')[1].split(':')[1][:-1]
        localLargeFile = os.path.join(
            os.getcwd(),
            '.git', 'lfs', 'objects', oid[:2], oid[2:4],
            oid,
        )
        # LFS Spec states that pointer files should not have the executable bit set.
        gitMode = '100644'
        return (gitMode, pointerContents, localLargeFile)

    def pushFile(self, localLargeFile):
        uploadProcess = subprocess.Popen(
            ['git', 'lfs', 'push', '--object-id', 'origin', os.path.basename(localLargeFile)]
        )
        if uploadProcess.wait():
            die('git-lfs push command failed. Did you define a remote?')

    def generateGitAttributes(self):
        return (
            self.baseGitAttributes +
            [
                '\n',
                '#\n',
                '# Git LFS (see https://git-lfs.github.com/)\n',
                '#\n',
            ] +
            ['*.' + f.replace(' ', '[[:space:]]') + ' filter=lfs -text\n'
                for f in sorted(gitConfigList('git-p4.largeFileExtensions'))
            ] +
            ['/' + f.replace(' ', '[[:space:]]') + ' filter=lfs -text\n'
                for f in sorted(self.largeFiles) if not self.hasLargeFileExtension(f)
            ]
        )

    def addLargeFile(self, relPath):
        LargeFileSystem.addLargeFile(self, relPath)
        self.writeToGitStream('100644', '.gitattributes', self.generateGitAttributes())

    def removeLargeFile(self, relPath):
        LargeFileSystem.removeLargeFile(self, relPath)
        self.writeToGitStream('100644', '.gitattributes', self.generateGitAttributes())

    def processContent(self, git_mode, relPath, contents):
        if relPath == '.gitattributes':
            self.baseGitAttributes = contents
            return (git_mode, self.generateGitAttributes())
        else:
            return LargeFileSystem.processContent(self, git_mode, relPath, contents)

class Command:
    def __init__(self):
        self.usage = "usage: %prog [options]"
