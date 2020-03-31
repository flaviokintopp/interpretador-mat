#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<stdbool.h>

#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'
#define EXP '|'
#define SQRT '&'
int getNumber(char number);

int main()
{
  printf("Type the expression to be calculated\n");
  char expression[100], cleanExpression[100];
  scanf("%[^\n]s", expression);
  printf("Expression received is %s\n", expression);

  int length = strlen(expression);
  int i = 0, pos = 0;
  for (i = 0; i < length; i++, pos++)
  {
    if (expression[pos] == ' ')
      pos++;
     cleanExpression[i] = expression[pos];

  }
  cleanExpression[i] = '\0';
  int result = 0;
  int j = 0;

  char operator;
  char finalOperator;
  char numbers[10];
  int newLength = strlen(cleanExpression);
  int results[100];
  int resultPos = 0;
  for (i = 0; i < newLength; i++)
  {
    if (cleanExpression[i] == ')')
    {
      if (i == (newLength - 1) && resultPos > 1)
      {
        finalOperator = cleanExpression[i-1];
        break;
      }
      operator = cleanExpression[i-1];
      pos = 0;
      for (j = i-2; j >= 0; j--)
      {
        if (cleanExpression[j] == '(')
        {
          break;
        }
        numbers[pos] = cleanExpression[j];
        pos++;
      }
      numbers[pos] = '\0';
      int x = 0;
      int y = 0;
      switch (operator)
      {
      case ADD:
        results[resultPos] = 0;
        j = strlen(numbers) - 1;
        while (j >= 0)
        {
          x = getNumber(numbers[j]);
          results[resultPos] += x;
          j--;
        }
        break;
      case SUB:
        results[resultPos] = 0;
        j = strlen(numbers) - 1;
        x = getNumber(numbers[j]);
        results[resultPos] = x;
        j -= 1;
        while (j >= 0)
        {
          x = getNumber(numbers[j]);
          results[resultPos] -= x;
          j--;
        }
        break;
      case MULT:
        results[resultPos] = 0;
        j = strlen(numbers) - 1;
        x = getNumber(numbers[j]);
        y = getNumber(numbers[j-1]);
        j -= 2;
        results[resultPos] = x*y;
        while (j >= 0)
        {
          x = getNumber(numbers[j]);
          results[resultPos] *= x;
          j--;
        }
        break;
      case DIV:
        results[resultPos] = 0;
        j = strlen(numbers) - 1;
        x = getNumber(numbers[j]);
        y = getNumber(numbers[j-1]);
        j -= 2;
        results[resultPos] = x/y;
        while (j >= 0)
        {
          x = getNumber(numbers[j]);
          results[resultPos] /= x;
          j--;
        }
        break;
      case EXP:
        results[resultPos] = 0;
        j = strlen(numbers) - 1;
        x = getNumber(numbers[j]);
        y = getNumber(numbers[j-1]);
        j -= 2;
        results[resultPos] = pow(x,y);
        while (j >= 0)
        {
          x = getNumber(numbers[j]);
          results[resultPos] = pow(result,x);
          j--;
        }
        break;
      case SQRT:
        results[resultPos] = 0;
        j = strlen(numbers) - 1;
        x = getNumber(numbers[j]);
        results[resultPos] = sqrt(x);
        break;
      }
      resultPos++;
    }
  }

  if(resultPos == 1)
  {
    printf ("Result = %d\n", results[0]);
    return 0;
  }
  int x = 0;
  int y = 0;
  int k = 0;
  switch (finalOperator)
  {
  case ADD:
    while (k < resultPos)
    {
      result += results[k];
      k++;
    }
    break;
  case SUB:
    result = results[k];
    k += 1;
    while (k < resultPos)
    {
      result -= results[k];
      k++;
    }
    break;
  case MULT:
    x = results[k];
    y = results[k+1];
    k += 2;
    result = x*y;
    while (k < resultPos)
    {
      x = results[k];
      result *= x;
      k++;
    }
    break;
  case DIV:
    x = results[k];
    y = results[k+1];
    k += 2;
    result = x/y;
    while (k < resultPos)
    {
      result /= results[k];
      k++;
    }
    break;
  case EXP:
    x = results[k];
    y = results[k+1];
    k += 2;
    result = pow(x,y);
    while (k < resultPos)
    {
      result = pow(result, results[k]);
      k++;
    }
    break;
  case SQRT:;
    result = sqrt(results[k]);
    break;
  }

  printf ("Result = %d\n", result);
  return 0;
}

// itoa e atoi não estavam funcionando na IDE em que desenvolvi
int getNumber(char number)
{
  int result = 0;
  switch (number)
  {
  case '0':
    result = 0;
    break;
  case  '1':
    result = 1;
    break;
  case '2':
    result = 2;
    break;
  case  '3':
    result = 3;
    break;
  case '4':
    result = 4;
    break;
  case  '5':
    result = 5;
    break;
  case '6':
    result = 6;
    break;
  case  '7':
    result = 7;
    break;
  case '8':
    result = 8;
    break;
  case  '9':
    result = 9;
    break;
  }
  return result;
}

