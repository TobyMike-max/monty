#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_num);
void monty_sub(stack_t **stack, unsigned int line_num);
void monty_div(stack_t **stack, unsigned int line_num);
void monty_mul(stack_t **stack, unsigned int line_num);
void monty_mod(stack_t **stack, unsigned int line_num);

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void monty_add(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "add"));
		return;
	}
	
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_sub - Subtracts the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_div - Divides the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void monty_div(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_mul - Multiplies the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_num);
}

/**
 * monty_mod - Computes the modulus of the second value from the
 * top of a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_num, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_num));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_num);
}
