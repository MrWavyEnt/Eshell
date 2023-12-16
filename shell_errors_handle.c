#include "main.h"

/**
 * print_error - Displays error message
 * @in_u: Input recieved from user
 * @cntsh: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */

void print_error(char *in_u, int cntsh, char **argv)
{
	char *chrr;

	PRINT(argv[0]);
	PRINT(": ");
	chrr = _itoa(cntsh);
	PRINT(chrr);
	free(chrr);
	PRINT(": ");
	PRINT(in_u);
	PRINT(": not found\n");
}

/**
 *  _prerror - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @ercount: Error Count
 * @bltcmd: Array of parsed command strings
 */

void _prerror(char **argv, int ercount, char **bltcmd)
{
	char *chrr = _itoa(ercount);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(chrr);
	PRINT(": ");
	PRINT(bltcmd[0]);
	PRINT(": Illegal number: ");
	PRINT(bltcmd[1]);
	PRINT("\n");
	free(chrr);
}

/**
 * error_file - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @ercount: Error Count
 */
void error_file(char **argv, int ercount)
{
	char *chrr = _itoa(ercount);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(chrr);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(chrr);
}

