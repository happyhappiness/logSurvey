#include <sys/types.h>
#include <unistd.h>

Ipc::Mem::Segment::Segment(const char *const id):
    theName(GenerateName(id)), theFD(-1), theSize(-1), theMem(NULL)
{
}

Ipc::Mem::Segment::~Segment() {
    if (theFD >= 0) {
        detach();
        if (close(theFD) != 0)
            debugs(54, 5, HERE << "close: " << xstrerror());
    }
}

void
Ipc::Mem::Segment::create(const int aSize)
{
    assert(aSize > 0);
    assert(theFD < 0);

    theFD = shm_open(theName.termedBuf(), O_CREAT | O_RDWR | O_TRUNC,
                     S_IRUSR | S_IWUSR);
    if (theFD < 0) {
        debugs(54, 5, HERE << "shm_open: " << xstrerror());
        fatal("Ipc::Mem::Segment::create failed to shm_open");
    }

    if (ftruncate(theFD, aSize)) {
        debugs(54, 5, HERE << "ftruncate: " << xstrerror());
        fatal("Ipc::Mem::Segment::create failed to ftruncate");
    }

    theSize = aSize;
