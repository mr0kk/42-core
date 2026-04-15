#include "../include/philo.h"

static int	handle_mutex_error(int status, t_opcode op_code)
{
	if (status == 0)
		return (0);
	if (status == EINVAL && (op_code == LOCK || op_code == UNLOCK))
		return (return_message("invalid value specified by mutex", 1));
	else if (status == EINVAL && op_code == INIT)
		return (return_message("invalid value specified by attr", 1));
	else if (status == EDEADLK)
		return (return_message("deadlock will occur if thread blocked waiting for mutex", 1));
	else if (status == EPERM)
		return (return_message("currend thread does not hold a lock mutex", 1));
	else if (status == ENOMEM)
		return (return_message("process cannot allocate enought memory for mutex", 1));
	else if (status == EBUSY)
		return (return_message("Mutex is locked", 1));
			 
}

/*
	returns 0 when everything set correctly
*/
int	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode op_code)
{
	if (op_code == LOCK)
		return (handle_mutex_error(pthread_mutex_lock(mutex), LOCK));
	else if (op_code == UNLOCK)
		return (handle_mutex_error(pthread_mutex_unlock(mutex), UNLOCK));
	else if (op_code == INIT)
	return (handle_mutex_error(pthread_mutex_init(mutex), INIT));
	else if (op_code == DESTROY)
		return (handle_mutex_error(pthread_mutex_destroy(mutex), DESTROY));
	return (return_message("Error: wrong opcode for handle mutex", 1));
}

static int	handle_thread_error(int status, t_opcode op_code)
{
	if (status == 0)
		return (0);
	if (status == EAGAIN)
		return (return_message("no resources to create another thread", 1));
	else if (status == EPERM && op_code == CREATE)
		return (return_message("caller does not have appropriate permission", 1));
	else if (status == EINVAL && op_code == CREATE)
		return (return_message("value specified by attr is invalid", 1));
	else if (status == EINVAL && (op_code == JOIN || op_code == DETACH))
		return (return_message("value specified by thread is not joinable", 1));
	else if (status == ESRCH)
		return (return_message("no thread could be found with this thread ID", 1));
	else if (status == EDEADLK)
		return (return_message("deadlock was detected", 1));
			 
}

/*
	returns 0 when everything set correctly
*/
int	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
					 void *data,  t_opcode op_code)
{
	if (op_code == CREATE)
		return (handle_thread_error(pthread_create(thread, NULL, foo, data), op_code));
	else if (op_code == JOIN)
		return (handle_thread_error(pthread_join(*thread, NULL), op_code));
	else if (op_code == DETACH)
		return (handle_thread_error(pthread_detach(*thread), op_code));
	return (return_message("Error: wrong opcode for handle thread", 1));
}
