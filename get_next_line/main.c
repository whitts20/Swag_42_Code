#include "get_next_line.h"

bool	hasleaks();
void	listleaks(bool unique);

int	main(void)
{
	int	rtn;
	char *print;

	rtn = open("./gnlTester/files/42_with_nl", O_RDONLY);
	print = get_next_line(rtn);
	/*if (hasleaks())
	{
		listleaks(true);
	}*/
}