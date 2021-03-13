/*
 * @Author       : Darcy
 * @Date         : 2021-01-14 23:00:59
 * @LastEditors  : Darcy
 * @LastEditTime : 2021-01-28 00:33:38
 * @FilePath     : \Practices\C\exercise\E1E.c
 * @Description  : <(￣︶￣)↗[GO!]
 * https://github.com/Darcy-Zhang
 */
#include <stdio.h>
#include <string.h>

static int calc(char s[]);

int main(void)
{

   char name[111][111], id[111][111], temp[111][111], find[111];
   int grade[111], list[111];
   int i, n, x = 1;
   int f, g, count;
   int a, b;
   int truth[111] = {0};
   int position[111];

   (void)scanf("%d%s", &n, find);
   for (i = 1; i <= n; i++)
   {
      (void)scanf("%s%s%s", name[i], id[i], temp[i]);
      grade[i] = calc(temp[i]);
   }

   for (i = 1; i <= n; i++)
      list[i] = i;

   while (x)
   {
      x = 0;
      for (i = 1; i < n; i++)
      {
         a = list[i];
         b = list[i + 1];
         if (grade[a] < grade[b])
         {
            list[i] = b;
            list[i + 1] = a;
            x = 1;
         }
      }
   }

   count = 1;
   f = list[1];
   position[f] = 1;
   for (i = 1; i < n; i++)
   {
      f = list[i];
      g = list[i + 1];
      if (grade[f] != grade[g])
         count = i + 1;

      position[g] = count;
   }

   for (i = 1; i <= n; i++)
   {
      if (strstr(name[i], find) != NULL || strstr(id[i], find) != NULL)
         truth[i] = 1;

      if (strcmp(find, temp[i]) == 0)
         truth[i] = 1;
   }

   for (i = 1; i <= n; i++)
   {
      if (truth[i])
      {
         if (grade[i] == -1)
            printf("%s %s %s n/a\n", name[i], id[i], temp[i]);
         else
            printf("%s %s %s %d\n", name[i], id[i], temp[i], position[i]);
      }
   }

   return 0;
}

static int calc(char s[])
{
   int z = (int)strlen(s);
   if (s[0] == 'n')
      return -1;
   int res = 0, h;
   for (h = 0; h < z; h++)
      res = res * 10 + s[h] - '0';

   return res;
}
