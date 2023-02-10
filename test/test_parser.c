#include "parser.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Test the parse_command function
 */
int test_parse_command(void)
{
    char input[] = "ls -l\n";
    char *argv[100];
    int argc = parse_command(input, argv);

    assert(argc == 2);
    assert(strcmp(argv[0], "ls") == 0);
    assert(strcmp(argv[1], "-l") == 0);

    return 0;
}

int main(void)
{
    test_parse_command();
    return 0;
}

