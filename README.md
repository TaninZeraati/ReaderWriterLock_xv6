

## Adding a New Feature In Spine Lock
For recursive functions one process can't acquire the lock twice.\
By adding a process to the lock attributes now the process that has acquire the lock can do it again and agian befor releasing the   
lock.\
Try it by calling "fact <number>" system call.

  ### Change in:
  spinelock.c\
  spinelock.h
  #### adding new system call:
  syscall.h\
  syscall.c\
  sysproc.c\
  usys.s\
  proc.c\
  proc.h\
  user.h\
  makefile
  
 
## Reader and Writer Lock
Creating a reader and writer lock using mutex.\
It changes the entered number to binary form and each 0 stands for a writer and each 1 is for a reader.\
Try it by using "test_rwp <number in decimal>" systemcall.

  ### Change:
  adding new system call.\
  adding a new lock (mutex) in proc.h.\
  using the lock and new functions in proc.c
  

