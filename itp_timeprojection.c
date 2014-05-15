/*
28.11.13
Calculator for projected time for tasks in ITP-1

For a project that lasts 80 days and has to be finished by January 13.

Asks you to enter time spent on task so far, as well as number of days left until the deadline.

Calculates projected time (based on the assumption you will spend as much time on it
in the future as you have in the past).

For every subsequent task, assumes time left until the deadline is the same as for the first one.

*/

#include <stdio.h>


int main(){

    int otherTask, futuredays;
    int firstRun = 1;

    do
    {
	float spentTime = 0;
	printf("Enter the individual times (20 at most) spent on the task so far\nin hours, separated by a space; end with a 0: ");

	for(int i=0; i<20; i++){
		float temporary = 0;
		scanf("%f", &temporary);
		if (temporary==0) break;
		else spentTime = spentTime+temporary;
	}

    int pastdays;
    int daystotal = 80;
	float projectedTimeFuture, projectedTimeTotal;

    if (firstRun==1)
    {
        printf("Enter time remaining until Jan 13 in days: ");
        scanf("%d", &futuredays);
    }

    pastdays = daystotal - futuredays;
    projectedTimeFuture = (spentTime/pastdays)*futuredays;
    projectedTimeTotal = projectedTimeFuture + spentTime;

    printf("Total time spent on task so far: %f\n", spentTime);
    printf("Projected time yet to spend on task): %f\n", projectedTimeFuture);
    printf("Projected total to spend on task: %f\n", projectedTimeTotal);

    printf("Other task? (0 for no, 1 for yes): ");
    scanf("%d", &otherTask);
    if (firstRun==1) firstRun=0;

    }
    while(otherTask==1);

	return 0;
}
