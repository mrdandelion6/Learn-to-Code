#define _GNU_SOURCE

// ------------
// This code is provided solely for the personal and private use of
// students taking the CSC367H5 course at the University of Toronto.
// Copying for purposes other than this use is expressly prohibited.
// All forms of distribution of this code, whether as given or with
// any changes, are expressly prohibited.
//
// Authors: Bogdan Simion, Alexey Khrabrov
//
// All of the files in this directory and all subdirectories are:
// Copyright (c) 2024 Bogdan Simion
// -------------

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "time_util.h"

// corresponds to number of columns (i,e row length)
#define NVECS 10000 

// corresponds to number of rows (i,e column length)
#define NDIMS 10000

// so matrix is NDIMS x NVECS

static double ranf(void)
{
	return (double)random() / RAND_MAX;
}

void generate(double m[NDIMS][NVECS])
{
	srandom(42);
	for (int i = 0; i < NDIMS; i++) {
		for (int j = 0; j < NVECS; j++) {
			m[i][j] = ranf();
		}
	}
}


double avg_vec_len(const double m[NDIMS][NVECS])
{
	double squared_vector_sums[NVECS] = {0.0};

	for (int j = 0; j < NDIMS; j++) {
		for (int i = 0; i < NVECS; i++) {
			squared_vector_sums[i] += m[j][i] * m[j][i];
		}
	}

	double len_sum = 0.0;

	for ( int i = 0; i < NVECS; i++ ) {
		len_sum += sqrt(squared_vector_sums[i]);
	}

	return len_sum / NVECS; // average
}


double matrix[NDIMS][NVECS];

int main()
{
	generate(matrix);
 
	double time_msec = 0.0;
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	double avg_len = avg_vec_len(matrix);

	clock_gettime(CLOCK_MONOTONIC, &end);

	time_msec = timespec_to_msec(difftimespec(end, start));

	printf("%f\n", avg_len);
	printf("%f\n", time_msec);
	return 0;
}
