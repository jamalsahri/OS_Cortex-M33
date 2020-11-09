#include <stdlib.h>
#include "kernel.h"
#include "list.h"

#ifndef NULL
#define NULL 0
#endif


/*****************************************************************************
 * Global variables
 *****************************************************************************/

static uint32_t id=1;
Task * tsk_running = NULL;	/* pointer to ready task list : the first
                                     node is the running task descriptor */
Task * tsk_prev = NULL;
Task * tsk_sleeping = NULL;	/* pointer to sleeping task list */

/*****************************************************************************
 * SVC dispatch
 *****************************************************************************/
/* sys_add
 *   test function
 */
int sys_add(int a, int b)
{
    return a+b;
}

/* syscall_dispatch
 *   dispatch syscalls
 *   n      : syscall number
 *   args[] : array of the parameters (4 max)
 */
int32_t svc_dispatch(uint32_t n, uint32_t args[])
{
    switch(n) {
      case 0:
          return sys_add((int)args[0], (int)args[1]);
          break;
      case 1:
    	  return malloc((int)args[0]);
    	  break;
      case 2:
      	  free((void*)args[0]);
      	  break;
      case 3:
    	  sys_os_start();
    	  break;
      case 4:
    	  return sys_task_new((TaskCode)args[0], (uint32_t)args[1]);
    	  break;
      case 5:
    	  return sys_task_id();
    	  break;
      case 6:
    	  return sys_task_wait((uint32_t)args[0]);
          break;
      case 7:
    	  return sys_task_kill();
    	  break;
      case 8:
    	  return sys_sem_new((int32_t)args[0]);
    	  break;
      case 9:
    	  return sys_sem_p((Semaphore*)args[0]);
    	  break;
      case 10:
    	  return sys_sem_v((Semaphore*)args[0]);
    	  break;
    }
    return -1;
}

void sys_switch_ctx()
{
	SCB->ICSR |= 1<<28; // set PendSV to pending
}
/*****************************************************************************
 * Round robin algorithm
 *****************************************************************************/
#define SYS_TICK  10	// system tick in ms

uint32_t sys_tick_cnt=0;

/* tick_cb
 *   system tick callback: task switching, ...
 */
void sys_tick_cb()
{
	/* A COMPLETER */

//    list_display(tsk_running);
}

void SysTick_Handler(void)
{
	sys_tick_cnt++;

	if (sys_tick_cnt == SYS_TICK) {
		sys_tick_cnt = 0;
		sys_tick_cb();
	}
}

/*****************************************************************************
 * General OS handling functions
 *****************************************************************************/

/* sys_os_start
 *   start the first created task
 */
int32_t sys_os_start()
{
	/* A COMPLETER */

    // Reset BASEPRI
    __set_BASEPRI(0);

	// Set systick reload value to generate 1ms interrupt
    SysTick_Config(SystemCoreClock / 1000U);
    return 0;
}

/*****************************************************************************
 * Task handling functions
 *****************************************************************************/
void task_kill();

/* sys_task_new
 *   create a new task :
 *   func      : task code to be run
 *   stacksize : task stack size
 *
 *   Stack frame:
 *      |    xPSR    |
 *      |     PC     |
 *      |     LR     |
 *      |     R12    |    ^
 *      |     R3     |    ^
 *      |     R2     |    | @++
 *      |     R1     |
 *      |     R0     |
 *      +------------+
 *      |     R11    |
 *      |     R10    |
 *      |     R9     |
 *      |     R8     |
 *      |     R7     |
 *      |     R6     |
 *      |     R5     |
 *      |     R4     |
 *      +------------+
 *      | EXC_RETURN |
 *      |   CONTROL  | <- sp
 *      +------------+
 */
int32_t sys_task_new(TaskCode func, uint32_t stacksize)
{
	// get a stack with size multiple of 8 bytes
	uint32_t size = stacksize>96 ? 8*(((stacksize-1)/8)+1) : 96;
	
	Task * newTask;
	newTask = (Task*)malloc(sizeof(Task));
	if(newTask!=NULL){
		//newTask->splim = malloc(sizeof(uint32_t)*size);
		newTask->splim = &size;
		newTask->delay = 0 ;
		newTask->id = id++;
		newTask->status = TASK_READY;
		//newTask->sp
		tsk_running = list_insert_tail(tsk_running, newTask);
		//start func
	}
    return 0;
}

/* sys_task_kill
 *   kill oneself
 */
int32_t sys_task_kill()
{
	/* A COMPLETER */

	return 0;
}

/* sys_task_id
 *   returns id of task
 */
int32_t sys_task_id()
{
	/* A COMPLETER */

    return 0;
}


/* sys_task_yield
 *   run scheduler to switch to another task
 */
int32_t sys_task_yield()
{

    return -1;
}

/* task_wait
 *   suspend the current task until timeout
 */
int32_t sys_task_wait(uint32_t ms)
{
	/* A COMPLETER */

    return 0;
}


/*****************************************************************************
 * Semaphore handling functions
 *****************************************************************************/

/* sys_sem_new
 *   create a semaphore
 *   init    : initial value
 */
Semaphore * sys_sem_new(int32_t init)
{
	/* A COMPLETER */

    return NULL;
}

/* sys_sem_p
 *   take a token
 */
int32_t sys_sem_p(Semaphore * sem)
{
	/* A COMPLETER */

	return -1;
}

/* sys_sem_v
 *   release a token
 */
int32_t sys_sem_v(Semaphore * sem)
{
	/* A COMPLETER */

	return -1;
}
