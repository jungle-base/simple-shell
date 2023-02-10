#include "main.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Test the run_command function
 */
int test_run_command(void)
{
    char input[] = "ls -l\n";
    int result = run_command(input);

    assert(result == 0);

    return 0;
}

int main(void)
{
    test_run_command();
    return 0;
}

