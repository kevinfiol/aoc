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

int main(void) {
  int left_column[MAX_LINES];
  int right_column[MAX_LINES];
  int line_count = 0;
  int sum = 0;

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

  for (int i = 0; i < line_count; i++) {
    sum += abs(left_column[i] - right_column[i]);
  }

  printf("Total difference: %d\n", sum);

  return 0;
}