#include<stdio.h>

void tower(int n, char source, char temp, char destination) {
    if(n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", source, destination);
        return;
    }
    tower(n-1, source, destination, temp);
    printf("\n Move disk %d from rod %c to rod %c", n, source, destination);
    tower(n-1, temp, source, destination);
}

int main() {
    int n;
    printf("\n Enter the number of discs: ");
    scanf("%d", &n);
    printf("\n The sequence of moves involved in the Tower of Hanoi are:\n");
    tower(n, 'A', 'B', 'C');
    printf("\n\n Total number of moves: %d\n", (1 << n) - 1);
    return 0;
}
