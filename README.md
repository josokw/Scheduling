Scheduling
=============
Console application implemented in C++. 

Scheduling strategies:
- RMA
- EDF (not implemented yet)
- LL (not implemented yet)

Output
------

    ---- schedule v0.1.0 started

    T1   1 5 5
    T2   2 10 10
    T3   5 15 15

    Sufficient schedulable? 0.733333 <= 0.779763
    Tasks are schedulable!
    Timeslice = 1  Minorframe = 5  Majorframe = 30

    T1  !x....!x....!x....!x....!x....!x....!
    T2  !.xx.. .....!.xx.. .....!.xx.. .....!
    T3  !...xx .xxx. .....!.xxxx ...x. .....!

    T1   1 5 5
    T2   2 10 10
    T3   8 15 15

    Sufficient schedulable? 0.933333 <= 0.779763
    Tasks are schedulable?
    Timeslice = 1  Minorframe = 5  Majorframe = 30

    T1  !x....!x....!x....!x....!x....!x....!
    T2  !.xx.. .....!.xx.. .....!.xx.. .....!
    T3  !...xx .xxxx ...xx!.xxxx ...xx .xx..!

    T1   4 16 16
    T2   8 32 32
    T3   32 64 64

    Sufficient schedulable? 1 <= 0.779763
    Tasks are schedulable?
    Timeslice = 4  Minorframe = 16  Majorframe = 64

    T1  !xxxx............!xxxx............!xxxx............!xxxx............!
    T2  !....xxxxxxxx.... ................!....xxxxxxxx.... ................!
    T3  !............xxxx ....xxxxxxxxxxxx ............xxxx ....xxxxxxxxxxxx!

    ---- ended


Building
--------
This program does not need any external libs. 
The makefile is in the src directory.
Build it:
  
    make

Executing
---------

    ./schedule
