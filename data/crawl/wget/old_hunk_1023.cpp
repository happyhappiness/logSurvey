      /* Incomplete or invalid multibyte sequence */
      if (errno == EINVAL || errno == EILSEQ)
        {
          invalid++;
          **out = *in;
          in++;
src/ChangeLog |  8 ++++++++
src/host.c    | 21 +++++++++++++++++++--
src/iri.c     | 21 ++++++++++++++++++++-
src/iri.h     |  2 ++
4 files changed, 49 insertions(+), 3 deletions(-)
