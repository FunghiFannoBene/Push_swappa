ft_swap(int *val1, int*val2)
{
	int tmp;
	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

ft_double_swap(int *val1, int *val2, int *val3, int*val4)
{
	int tmp;
	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
	tmp = *val3;
	*val3 = *val4;
	*val4 = tmp;
}