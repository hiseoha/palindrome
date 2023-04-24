#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "Stack Full\n");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
		return;
	}
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty\n");
		return;
	}
	else return s->data[(s->top--)];
}

int palindrome_check(char str[]) {
	bool result = true;
	StackType s;
	init_stack(&s);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != " ") {
			char c = tolower(str[i]);
			push(&s, c);
		}
	}

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != pop(&s)) {
			return result = false;
		}
		else return result = true;
	}
}

int main() {
	bool cont = true;

	while (cont)
	{
		char str[MAX_STACK_SIZE];
		char ans[10];

		printf("문자열을 입력하세요: ");
		gets(str);

		if (palindrome_check(str)) printf("%s is a palindrome.\n", str);
		else printf("%s is not a palindrome.\n", str);

		printf("\n계속 입력하시겠습니까? (Yes/No): ");
		gets(ans);

		if (ans == "no" || ans == "No" || ans == "NO" || ans == "nO") {
			printf("End");
			cont = false;
		}
	}
	return 0;
}