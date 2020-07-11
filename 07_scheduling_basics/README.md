# Homework (Simulation)

This program, `scheduler.py` , allows you to see how different schedulers perform under scheduling metrics such as response time, turnaround time, and total wait time.

## Questions

1) Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.

    - FIFO response times:
        - Job 0: 0
        - Job 1: 200
        - Job 2: 400
    - FIFO turnaround times:
        - Job 0: 200
        - Job 1: 400
        - Job 2: 600
    - SJF turnaround and response times are the same as FIFO in this case; because the jobs are all the same length, the order in which they run doesn't matter (in terms of metrics).

2) Now do the same but with jobs of different lengths: 100, 200, and 300.

    - FIFO response times:
        - Job 0: 0
        - Job 1: 100
        - Job 2: 300
    - FIFO turnaround times:
        - Job 0: 100
        - Job 1: 300
        - Job 2: 600
    - Again, SJF times will be the same in this case because the jobs are already coming in shortest-to-longest.

3) Now do the same, but also with the RR scheduler and a time-slice of 1.

4) For what types of workloads does SJF deliver the same turnaround times as FIFO?

5) For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

6) What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?

7) What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given *N* jobs?
