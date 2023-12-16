#include "main.h"

/**
 * exit_bul - Exit Status for built-in commands
 * @bltcmd: Array of parsed command strings
 * @in_u: Input recieved from the user (to be freed)
 * @argv: Argument to be passed before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution counter
 * @e_state: Exit status
 */
void exit_bul(char **bltcmd, char *in_u, char **argv, int c, int e_state)
{
        int status, abc = 0;

        if (bltcmd[1] == NULL)
        {
                free(in_u);
                free(bltcmd);
                exit(e_state);
        }
        while (bltcmd[1][abc])
        {
                if (_isalpha(bltcmd[1][abc++]) != 0)
                {
                        _prerror(argv, c, bltcmd);
                        free(in_u);
                        free(bltcmd);
                        exit(2);
                }
                else
                {
                        status = _atoi(bltcmd[1]);
                        if (status == 2)
                        {
                                _prerror(argv, c, bltcmd);
                                free(in_u);
                                free(bltcmd);
                                exit(status);
                        }
                        free(in_u);
                        free(bltcmd);
                        exit(status);

                }
        }
}
