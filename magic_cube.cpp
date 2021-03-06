// magic_cube.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include "math.h"

int cube[3][3] = { {4,9,2},{3,5,7},{8,1,5} };
int answer[8][3][3] = { { {8,1,6}, {3,5,7}, {4,9,2} },{{ 4,9,2 },{ 3,5,7 },{ 8,1,6 }},{{ 2,9,4 },{ 7,5,3 },{ 6,1,8 }},
						{ { 6,1,8 },{ 7,5,3 },{ 2,9,4 } },{ { 2,7,6 },{ 9,5,1 },{ 4,3,8 } },{ { 4,3,8 },{ 9,5,1 },{ 2,7,6 } },
						{ { 8,3,4 },{ 1,5,9 },{ 6,7,2 } },{ { 6,7,2 },{ 1,5,9 },{ 8,3,4 } } } ;
int sum_arr[9];
void print_cube() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			printf("%d",cube[row][col]);
		}
		printf("\n");
	}
}

void generate_cube() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cube[row][col] = rand() % 9 + 1;
		}
	}
}

void calculate_sum() {
	int sum = 0;
	int *best;
	for (int sum_count = 0; sum_count < 8; sum_count++) {
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				sum += abs((answer[sum_count][row][col]) - (cube[row][col]));
			}
		}
		sum_arr[sum_count] = sum;
		sum = 0;
	}
	best = std::min_element(sum_arr, sum_arr + 8);
	printf("best: %d\n", *best);
}

int main()
{
	//generate_cube();
	calculate_sum();
    return 0;
}


