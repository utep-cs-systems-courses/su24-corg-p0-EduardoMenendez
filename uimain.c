#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");
  void (*print_function)(char);

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Chars = c, Arrow = a) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'a':
      puts("You selected arrow:");
      print_arrow(8,8);
      break;
    case 'c':
      puts("You selected chars, select the orientation and font of the characters to print (5x7 vertical = 1, 8x12 vertical = 2, 8x12 horizontal = 3)");
      getchar();
      switch(getchar()){
        case '1':
            print_function = &print_char_5x7;
            break;
        case '2':
            print_function = &print_char_8x12_horizontal;
            break;
        case '3':
            print_function = &print_char_8x12;
            break;
        default:
            print_function = &print_char_8x12_horizontal;
        }
      for (char c = 'a'; c < 'd'; c++)
	    print_function(c);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
