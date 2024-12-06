#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 2000

int compare_sort_fn(const void *a, const void *b) {
  int *num_a = (int *)a; // cast to an int pointer
  int *num_b = (int *)b;
  int val_a = *num_a; // dereference
  int val_b = *num_b;
  return val_a - val_b;
}

void part_one(int *left_column, int *right_column, int line_count) {
  int sum = 0;

  for (int i = 0; i < line_count; i++) {
    sum += abs(left_column[i] - right_column[i]);
  }

  printf("Total difference: %d\n", sum);
}

void part_two(int *left_column, int *right_column, int line_count) {
  int i = 0;
  int j = 0;
  int sum = 0;

  int counts[line_count];

  // initialize counts
  for (int x = 0; x < line_count; x++) {
    counts[x] = 0;
  }

  // now count how many times elements in the left column show up in the right column
  while (i < line_count && j < line_count) {
    if (left_column[i] == right_column[j]) {
      counts[i] += 1;
      j++;
    } else if (left_column[i] < right_column[j]) {
      i += 1;
      j = 0;
    } else {
      j += 1;
    }
  }

  // now multiply each and get the sum
  for (int y = 0; y < line_count; y++) {
    int multiplier = counts[y];
    int number = left_column[y];
    sum += (number * multiplier);
  }

  printf("Total multiplier sum: %d\n", sum);
}

int main(void) {
  int left_column[MAX_LINES];
  int right_column[MAX_LINES];
  int line_count = 0;

  FILE *input = fopen("input.txt", "r");
  if (!input) {
    fprintf(stderr, "Error opening input.txt file\n");
    return 1;
  }

  while (
    fscanf(input, "%d   %d", &left_column[line_count], &right_column[line_count]) == 2
  ) {
    line_count += 1;

    if (line_count >= MAX_LINES) {
      fprintf(stderr, "Reached max number of lines\n");
      break;
    }
  }

  fclose(input);

  qsort(left_column, line_count, sizeof(int), compare_sort_fn);
  qsort(right_column, line_count, sizeof(int), compare_sort_fn);

  part_one(left_column, right_column, line_count);
  part_two(left_column, right_column, line_count);

  return 0;
}