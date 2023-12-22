#include "main.h"

/**
 * run_calculator - Runs a simple calculator mode within the shell.
 */

void run_calculator(void)
{
	char user_input[256];
	int num1, num2;
	char operator[2];
	int result = 0;


	printf("\033[35mCalc mode\033[0m\n");
	printf("\033[35mUse format \"num operator num\" and press enter\033[0m\n");
	printf("\033[31mUse \"exit\" command to exit calc mode\033[0m\n");
	printf("\033[35mCalc mode\033[0m: ");

	while (fgets(user_input, sizeof(user_input), stdin))
	{
		if (strcmp(user_input, "exit\n") == 0)
			break;

		if (sscanf(user_input, "%d %1s %d", &num1, operator, &num2) == 3)
		{
			result = calculate(num1, operator, num2);
			if (result == -1)
				printf("Cannot divide by 0\n");
			else
				printf("Result: %d\n", result);
		}
		else
			printf("Invalid format: use \"num operator num\"\n");

		printf("\033[35mCalc mode\033[0m: ");
	}
}

/**
 * calculate - Performs basic arithmetic operations based
 * on the given operands and operator.
 * @num1: First operand as an integer.
 * @operator: Operator as a string, which can be +, -, *, /, or %.
 * @num2: Second operand as an integer.
 * Return: The result of the arithmetic operation as an integer,
 * or -1 in case of division by zero.
 */

int calculate(int num1, char *operator, int num2)
{
	if (strcmp(operator, "+") == 0)
		return (num1 + num2);

	if (strcmp(operator, "-") == 0)
		return (num1 - num2);

	if (strcmp(operator, "/") == 0)
	{
		if (num2 == 0)
			return (-1);
		return (num1 / num2);
	}

	if (strcmp(operator, "*") == 0 || strcmp(operator, "x") == 0)
		return (num1 * num2);

	if (strcmp(operator, "%") == 0)
	{
		if (num2 == 0)
			return (-1);
		return (num1 % num2);
	}
	return (0);
}
