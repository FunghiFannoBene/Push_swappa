void ft_swap(int *val1, int*val2, char flag)
{
	int tmp;
	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
	if(flag == 'a')
		write(1, "sa", 2);
	else if(flag == 'b')
		write(1, "sb", 2);
}

void ft_double_swap(int *val1, int *val2, int *val3, int*val4)
{
	ft_swap(val1, val2, 1);
	ft_swap(val3, val4, 1);
	write(1, "ss", 2);
}
