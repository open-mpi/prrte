/*
 * $HEADER$
 */
#include "ompi_config.h"
#include <stdio.h>

#include "mpi.h"
#include "mpi/c/bindings.h"
#include "communicator/communicator.h"

#if OMPI_HAVE_WEAK_SYMBOLS && OMPI_PROFILING_DEFINES
#pragma weak MPI_Comm_free = PMPI_Comm_free
#endif

#if OMPI_PROFILING_DEFINES
#include "mpi/c/profile/defines.h"
#endif

static const char FUNC_NAME[] = "MPI_Comm_free";


int MPI_Comm_free(MPI_Comm *comm) 
{
    int ret;

    if ( MPI_PARAM_CHECK ) {
        OMPI_ERR_INIT_FINALIZE(FUNC_NAME);
        
        if ( NULL == *comm  || MPI_COMM_WORLD == *comm ||
             MPI_COMM_SELF == *comm  || ompi_comm_invalid (*comm)) {
            return OMPI_ERRHANDLER_INVOKE(MPI_COMM_WORLD, MPI_ERR_COMM, 
                                          FUNC_NAME);
        }
    }
    
    ret = ompi_comm_free ( comm ); 
    OMPI_ERRHANDLER_CHECK(ret, *comm, ret, FUNC_NAME);
    
    return MPI_SUCCESS;
}
