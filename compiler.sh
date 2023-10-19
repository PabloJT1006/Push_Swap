gcc -Wall -Werror ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_split.c ft_strlen.c ft_substr.c main.c stack_fts.c utils.c

echo ¨COMPILADO JUASJUAS\n¨

echo Test numeros bien
./a.out 41 5 1 +3 -7
echo Test con caracteres no correctos
./a.out 1 2 3 4 ñ 5
echo Test con duplicados
./a.out 1 2 3 4 4 5
