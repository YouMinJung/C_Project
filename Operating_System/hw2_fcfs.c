#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_LENGTH 1000

struct Process_Control_Block {
    int state; // 0: Not Running, 1: Running
    int time_serviced;
};

struct Process_Log {
    int entry_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

struct Process {
    int pid;
    int arrival_time;
    int service_time;
    struct Process_Control_Block pcb;
    struct Process_Log log;
};

int n;
struct Process *process_list;
int process_queue[MAX_QUEUE_LENGTH];
int f=0, r=0;
int queue_size=0;

struct Process create_process(int pid, int arrival_time, int service_time)
{
    struct Process p;

    p.pid = pid;
    p.arrival_time = arrival_time;
    p.service_time = service_time;
    p.pcb.state = 0; // Not Running
    p.pcb.time_serviced = 0;
    p.log.turnaround_time = 0;
    p.log.waiting_time = 0;
    p.log.response_time = 0;

    return(p);
}

void enqueue(int p)
{
    if (queue_size < MAX_QUEUE_LENGTH) {
        process_queue[r] = p;    
        r = (r+1)%MAX_QUEUE_LENGTH;
        queue_size ++;
    }
    else {
        printf("Error: queue is full\n");
    }
}

int dequeue()
{
    int fprev = f;
    f = (f+1)%MAX_QUEUE_LENGTH;
    queue_size --;
    return(process_queue[fprev]);
}

void report_log(int CPU_used, int total_time)
{
    int turnaround_sum = 0;
    int waiting_sum = 0;
    int response_sum = 0;
    int i;

    printf("\nLog of Process Scheduling\n");
    for(i=0;i<n;i++) {
        printf("PID(%d)", process_list[i].pid);
        printf("\tTurnaround Time: %d", process_list[i].log.turnaround_time);
        printf("\tWaiting Time : %d", process_list[i].log.waiting_time);
        printf("\tResponse Time : %d\n", process_list[i].log.response_time);
        turnaround_sum += process_list[i].log.turnaround_time;
        waiting_sum += process_list[i].log.waiting_time;
        response_sum += process_list[i].log.response_time;
    }
    printf("\nAverage Turnaround Time: %.2f\n", turnaround_sum / (float)n);
    printf("Average Waiting Time   : %.2f\n", waiting_sum / (float)n);
    printf("Average Response Time  : %.2f\n", response_sum / (float)n);
    printf("CPU Utilization        : %.2f%%\n", (CPU_used / (float)total_time)*100);
}

int main(int argc, char *argv[])
{
    FILE *process_file;
    int i, t;
    int total_time;
    int CPU_used;
    int CPU_idle;
    int num_processed;
    int current_process_index;
    int time_serviced;
    int pid, arrival_time, service_time;

    if (argc != 2) {
        printf("Usage: hw2_fcfs <process_file>\n");
        return(-1);
    }

    process_file=fopen(argv[1], "r");
    if (process_file==NULL) {
        printf("File open error: %s\n", argv[1]);
        return(-1);
    }

    fscanf(process_file, "%d", &n); // n: number of processes
    process_list = (struct Process *) malloc(sizeof(struct Process) * n);

    // construct process list
    for(i=0;i<n;i++) {
        pid, arrival_time, service_time;
        fscanf(process_file, "%d %d %d", &pid, &arrival_time, &service_time);
        struct Process p = create_process(pid, arrival_time, service_time);

        // add p to the end of process list
        process_list[i] = p;
    }
    fclose(process_file);

    CPU_used = 0;
    CPU_idle = 1;
    num_processed = 0;
    current_process_index = -1;
    t = 0;
    i = 0;

    // start of simulation
    while(num_processed < n) { // until all processes are processed
        // check if the current process can be flushed out from CPU
        if (current_process_index >= 0) {
            time_serviced = process_list[current_process_index].pcb.time_serviced;
            service_time = process_list[current_process_index].service_time;

            if (service_time == time_serviced) {
                printf("[%d] PID(%d): Exit\n", t, process_list[current_process_index].pid);
                num_processed++;
                process_list[current_process_index].log.turnaround_time = t - process_list[current_process_index].log.entry_time;
                CPU_idle = 1;
                current_process_index = -1;
                if (num_processed == n) break;
            }
        }

        while (t == process_list[i].arrival_time) {  // to handle processes that have same arrival time
            enqueue(i);
            process_list[i].log.entry_time = t;
            printf("[%d] PID(%d): Not-Running\n", t, process_list[i].pid);
            i++;
        }

        if (CPU_idle) {
            if (queue_size != 0) { // is queue not empty?
                current_process_index = dequeue();
                process_list[current_process_index].log.waiting_time += t - process_list[current_process_index].log.entry_time;
                if (process_list[current_process_index].log.response_time == 0) {
                	process_list[current_process_index].log.response_time = t - process_list[current_process_index].log.entry_time;
                }
                CPU_idle = 0;
                process_list[current_process_index].pcb.state = 1; // Running
                printf("[%d] PID(%d): Running\n", t, process_list[current_process_index].pid);
            }
        }

        if (!CPU_idle) {
            // CPU service one time tick for the process of current_process_index
            process_list[current_process_index].pcb.time_serviced++;
            CPU_used ++;
        }
        
        t++; // increase a time tick
    }

    total_time = t;

    report_log(CPU_used, total_time);

    return(0);
}

