#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int sctrace = 0;

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_getppid(void)
{
  return myproc()->parent->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// return the answer to life, meaning and everything else
int
sys_answer(void)
{
    return 42;
}

int
sys_sctrace(void)
{
    int n;  
    if(argint(0, &n) < 0)
        return -1;
    sctrace = n;
    return 0;
}

int 
sys_pgcnt(void)
{
    pde_t *pde;
    pte_t *pte;

    int i = 0;
    int j = 0;
    int cnt = 0;

    unsigned int flag = PTE_P | PTE_U;

    for (i=0; i < NPDENTRIES; i++) {
        pde = &((myproc()->pgdir)[i]);

        if (*pde & PTE_P) {
            pte = (pte_t*) P2V(PTE_ADDR(*pde));

            for (j=0; j < NPTENTRIES; j++) {
                if ((pte[j] & flag) == flag) {
                    cnt = cnt + 1;
                }
            }
        }
    }

    return cnt;
}

int
sys_pscnt(void)
{
    return pscnt();
}
