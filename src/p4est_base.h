
#ifndef __P4EST_BASE_H__
#define __P4EST_BASE_H__

#ifdef HAVE_CONFIG_H
#include <p4est_config.h>
#endif

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#if(defined HAVE_BACKTRACE && defined HAVE_BACKTRACE_SYMBOLS)
#define P4EST_BACKTRACE
#endif

#define P4EST_CHECK_ABORT(c,s)                     \
  do {                                             \
    if (!(c)) {                                    \
      fprintf (stderr, "Abort: %s\n   in %s:%d\n", \
               (s), __FILE__, __LINE__);           \
      p4est_abort ();                              \
    }                                              \
  } while (0)
#define P4EST_CHECK_ALLOC(p) P4EST_CHECK_ABORT (((p) != NULL), "Allocation")
#define P4EST_CHECK_MPI(r) P4EST_CHECK_ABORT ((r) == MPI_SUCCESS, "MPI operation")
#define P4EST_ASSERT(c) P4EST_CHECK_ABORT ((c), "Assertion '" #c "'")

#define P4EST_ALLOC(t,n) (t *) malloc ((n) * sizeof(t))
#define P4EST_ALLOC_ZERO(t,n) (t *) calloc ((n), sizeof(t))
#define P4EST_REALLOC(p,t,n) (t *) realloc ((p), (n) * sizeof(t))
#define P4EST_FREE(p) free (p)

void                p4est_abort (void);

#endif /* !__P4EST_BASE_H__ */