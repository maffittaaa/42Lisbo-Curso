
export SIZE=7

echo -e "\n\n\n//---------------------------------------------------	SIZE	=	${SIZE}	---------------------------------------------------\\\\\ \n\n"

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$SIZE -fsanitize=leak -fsanitize=address -g get_next_line.c get_next_line_utils.c main.c && ./a.out

export SIZE=1000

echo -e "\n\n\n//---------------------------------------------------	SIZE	=	${SIZE}	---------------------------------------------------\\\\\ \n\n"

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$SIZE -fsanitize=leak -fsanitize=address -g get_next_line.c get_next_line_utils.c main.c && ./a.out

export SIZE=1

echo -e "\n\n\n//---------------------------------------------------	SIZE	=	${SIZE}	---------------------------------------------------\\\\\ \n\n"

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$SIZE -fsanitize=leak -fsanitize=address -g get_next_line.c get_next_line_utils.c main.c && ./a.out

export SIZE=42

echo -e "\n\n\n//---------------------------------------------------	SIZE	=	${SIZE}	---------------------------------------------------\\\\\ \n\n"

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$SIZE -fsanitize=leak -fsanitize=address -g get_next_line.c get_next_line_utils.c main.c && ./a.out




