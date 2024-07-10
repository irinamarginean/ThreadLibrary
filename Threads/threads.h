#include <stdbool.h>

typedef int ult_thread_handle;

typedef enum {
	WAIT_FOR_THREAD, WAIT_FOR_MUTEX, RUNNING, DONE
} thread_status;

typedef struct {
	int id;
	thread_status status;
	ult_thread_handle awaited_thread;
	ult_thread_handle* awaited_mutex;
	ucontext_t execution_context;
};

typedef struct {
	ult_thread_handle owned_by;
	bool is_locked;
} ult_mutex_t;


void ult_init();
ult_thread_handle ult_create(void *(*f)(void*), void* arg);
bool ult_join(ult_thread_handle thread_handle, void** res);
ult_thread_handle ult_self();
void ult_exit();

