
#ifndef __P4EST_H__
#define __P4EST_H__

#include <p4est_memory.h>
#include <stdint.h>
#include <mpi.h>

typedef struct p4est_connectivity
{
  int32_t             num_trees;
  int32_t             num_vertices;
  int32_t            *tree_to_vertex;   /* allocated [0][0]..[0][3]
                                           .. [num_trees-1][0]..[num_trees-1][3] */
  int32_t            *tree_to_tree;     /* allocated [0][0]..[0][3]
                                           .. [num_trees-1][0]..[num_trees-1][3] */
  int8_t             *tree_to_face;     /* allocated [0][0]..[0][3]
                                           .. [num_trees-1][0]..[num_trees-1][3] */
}
p4est_connectivity_t;

typedef struct p4est_quadrant
{
  int32_t             x, y;
  int8_t              level;
  void               *user_data;
}
p4est_quadrant_t;

typedef struct p4est_tree
{
  p4est_array_t      *quadrants;        /* locally stored quadrants */
}
p4est_tree_t;

typedef struct p4est
{
  MPI_Comm            mpicomm;
  int                 mpisize, mpirank;

  int32_t             first_local_tree; /* 0-based index of first local tree */
  int32_t             local_num_trees;  /* number of trees on this processors */
  int32_t             local_num_quadrants;      /* number of quadrants
                                                   on all trees on this processor */
  int64_t             global_num_quadrants;     /* number of quadrants
                                                   on all trees on all processors */
  p4est_connectivity_t *connectivity;   /* connectivity structure */
  p4est_array_t      *trees;    /* list of all trees */
}
p4est_t;

p4est_connectivity_t *p4est_connectivity_new (int32_t num_trees,
                                              int32_t num_vertices);
void                p4est_connectivity_destroy (p4est_connectivity_t *
                                                connectivity);

p4est_t            *p4est_new (MPI_Comm mpicomm,
                               p4est_connectivity_t * connectivity);
void                p4est_destroy (p4est_t * p4est);

#endif /* !__P4EST_H__ */