#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"
#include "costum_logger.h"

volatile static int started = 0;
// #define INFO "Welcome to AUT MCS Principles of Operating Systems Course. This message is from a custom logger implemented by kasra"
// #define WARN "This is a test warning message for the custom logger"
// #define ERROR  "This is a test error message for the custom logger"

// start() jumps here in supervisor mode on all CPUs.
void
main()
{
  if(cpuid() == 0){
    consoleinit();
    printfinit();
    // printf("\n");
    // printf("xv6 kernel is booting\n");
    // printf("\n");
    logger("System is booting...", INFO);
    logger("Warning: Memory usage is high!", WARN);
    logger("Error: Kernel module failed to load!", ERROR);
    kinit();         // physical page allocator
    kvminit();       // create kernel page table
    kvminithart();   // turn on paging
    procinit();      // process table
    trapinit();      // trap vectors
    trapinithart();  // install kernel trap vector
    plicinit();      // set up interrupt controller
    plicinithart();  // ask PLIC for device interrupts
    binit();         // buffer cache
    iinit();         // inode table
    fileinit();      // file table
    virtio_disk_init(); // emulated hard disk
    userinit();      // first user process
    __sync_synchronize();
    started = 1;
  } else {
    while(started == 0)
      ;
    __sync_synchronize();
    printf("hart %d starting\n", cpuid());
    kvminithart();    // turn on paging
    trapinithart();   // install kernel trap vector
    plicinithart();   // ask PLIC for device interrupts
  }

  scheduler();        
}
