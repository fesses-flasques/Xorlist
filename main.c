#include	<stdlib.h>
#include	<stdio.h>
#include	<stdint.h>
#include	"xorlist.h"
Xormodule *s;

void
dump_it(void *t) {
  printf("%d\n", *(int *)t);
}

int
main() {
  Xorlist	*list = Xor_create();

  // Initializing the list by pushing back several values
  int	tab[] = {50, 150, 284, 6465};
  unsigned int	i = 0;
  while (i < sizeof(tab) / sizeof(*tab)) {
    if (Xor_pushback(list, tab + i) == EXIT_FAILURE)
      return (EXIT_FAILURE);
    ++i;
  }
  //
  printf("Foreach:\n");
  Xor_foreach(list, &dump_it);
  printf("Reverse Foreach:\n");
  Xor_foreach_rev(list, &dump_it);
  return (EXIT_SUCCESS);
}
