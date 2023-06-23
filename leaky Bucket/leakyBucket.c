#include<stdio.h>

int main(){
    int incoming, outgoing, buck_size, n, store = 0;

    // Prompt the user to enter bucket size, outgoing rate, and number of inputs
    printf("Enter bucket size, outgoing rate, and number of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n != 0) {
        // Prompt the user to enter the incoming packet size
        printf("Enter the incoming packet size: ");
        scanf("%d", &incoming);
        printf("Incoming packet size: %d\n", incoming);

        // Check if the incoming packet can be accommodated in the bucket buffer
        if (incoming <= (buck_size - store)){
            // Add the incoming packet size to the buffer
            store += incoming;
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        } else {
            // If the incoming packet exceeds the available space in the buffer, drop the excess packets
            printf("Dropped %d number of packets\n", incoming - (buck_size - store));
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
            store = buck_size;
        }

        // Simulate the outgoing packets and update the buffer size
        store = store - outgoing;
        printf("After outgoing %d packets left out of %d in buffer\n", store, buck_size);
        n--;
    }
}

