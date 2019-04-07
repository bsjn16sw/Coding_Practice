#include<stdio.h>
#define FLOOR 15
#define HOUSE 15

int apart[FLOOR][HOUSE];

int count_people(int floor, int house)
{	
	if(floor == 0 || house == 0)
		return apart[floor][house];

	apart[floor][house] = count_people(floor, house-1) + count_people(floor-1, house);
	
	return apart[floor][house];
}

int main()
{	
	int test, i, j, floor, house;
	
	for(j=0; j<HOUSE; j++){
		apart[0][j] = j;
	}
	
	for(i=1; i<FLOOR; i++){
		for(j=0; j<HOUSE; j++)
			apart[i][j] = 0;
		apart[i][1] = 1;
	}
	
	scanf("%d", &test);
	
	int floors[test];
	int houses[test];
	
	for(i=0; i<test; i++){
		scanf("%d", &floors[i]);
		scanf("%d", &houses[i]);
	}
	
	for(i=0; i<test; i++){
		printf("%d\n", count_people(floors[i], houses[i]));
	}
}
