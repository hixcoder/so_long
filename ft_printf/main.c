
#include "ft_printf.h"

int main()
{
	char		c = 'h';
	char		*s = "hello man";
	char		*p = NULL;
	int		d = -522; 
	int		i = -622; 
	unsigned int	u = 50;
	unsigned long	x = ULONG_MAX;
	unsigned long	X = ULONG_MAX;

	int count1;
	int count2;

	count1 = printf("  %c\n ", c);
	printf("count1 ====>  %d\n",count1);
	count1 = printf("  %s\n ", s);
	printf("count1 ====>  %d\n",count1);
	count1 = printf("  %p\n ", p);
	printf("count1 ====>  %d\n",count1);
	count1 = printf("  %d\n ", d);
	printf("count1 ====>  %d\n",count1);
	count1 = printf("  %i\n ", i);
	printf("count1 ====>  %d\n",count1);
	count1 = printf("  %u\n ", u);
	printf("count1 ====>  %d\n",count1);
	count1 = printf(">  %x\n ", x);
	printf("count1 ====>  %d\n",count1);
	count1 = printf("  %X\n ", X);
	printf("count1 ====>  %d\n",count1);
	count1 = printf("  %%\n ");
	printf("count1 ====>  %d\n",count1);
	//count1 = printf("  %c\n  %s\n  %p\n  %d\n  %i\n  %u\n  %x\n  %X\n  %%\n", c, s, p, d, i, u, x, X);
	//printf("count1 ====>  %d\n",count1);
	
	printf("-------------------------------\n");
	
	count2 = ft_printf("  %c\n ", c);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf("  %s\n ", s);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf("  %p\n ", p);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf("  %d\n ", d);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf("  %i\n ", i);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf("  %u\n ", u);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf(">  %x\n ", x);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf("  %X\n ", X);
	printf("count2 ====>  %d\n",count2);
	count2 = ft_printf("  %%\n ");
	printf("count2 ====>  %d\n",count2);
	//count2 = ft_printf("  %c\n  %s\n  %p\n  %d\n  %i\n  %u\n  %x\n  %X\n  %%\n", c, s, p, d, i, u, x, X);
	//printf("count2 ====>  %d\n",count2);

			//ft_printf("| %c |\n", '0');
	//printf("%i\n",i);
	
	printf("-------------------------------\n");
	printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return 0;
}

