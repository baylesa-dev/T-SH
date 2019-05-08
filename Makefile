##
## EPITECH PROJECT, 2017
## T-SH
## File description:
## Makefile
##

L_NAME		= libmy.a

AR_NAME		= $(addprefix lib/, $(L_NAME))

P_NAME		= t-sh

CFLAGS		= -W -Wall -Wextra -g

MAKEFLAGS	+= --silent

CPPFLAGS	= -Iinc

CC		= gcc

L_SRCS		=	$(addprefix lib/my/,	\
			my_putchar.c		\
			my_strlen.c		\
			my_putstr.c		\
			my_put_nbr.c		\
			my_strdup.c		\
			my_strcmp.c		\
			my_strncmp.c		\
			my_get_nbr.c		\
			my_list.c		\
			my_printf.c		\
			my_printf_ptr_func.c	\
			my_perror.c		\
			get_next_line.c)

P_SRCS		=	$(addprefix src/,	\
			main.c			\
			parser.c		\
			parser_semi_colon.c	\
			free.c			\
			list_binary_opt.c	\
			exec_command.c		\
			execution.c		\
			my_str_to_wordtab.c	\
			get_path.c		\
			my_spconcat.c		\
			copy_env.c		\
			parser_binary_opt.c)

P_SRCS		+=	$(addprefix src/builtin/,	\
			setenv.c			\
			tab.c				\
			unsetenv.c			\
			cd.c				\
			exit.c				\
			echo.c				\
			my_varconcat.c			\
			repeat.c			\
			var_interpreted.c		\
			my_dollarconcat.c		\
			where.c				\
			which.c				\
			quote.c)

P_SRCS		+=	$(addprefix src/pipe/,		\
			parser_pipe.c			\
			list_pipe.c			\
			command_table.c			\
			executor_pipe.c			\
			redirections_left.c		\
			redirections_right.c		\
			pipe_rw.c			\
			redirections_left_pipe.c	\
			redirections_right_pipe.c	\
			lexer_pipe.c			\
			cut_redirections.c		\
			get_input.c			\
			get_output.c			\
			swap_ptr.c			\
			process_pipe.c)

P_SRCS		+=	$(addprefix src/parser_cmd/,	\
			parser_cmd.c			\
			globbing.c			\
			my_tabconcat.c			\
			inhibitors.c)

P_SRCS		+=	$(addprefix src/pre_parser/,	\
			record.c			\
			usefull.c			\
			auto_complete.c			\
			record_display.c		\
			erase.c				\
			clean.c				\
			cursor.c			\
			control.c			\
			sequence.c			\
			alpha_num.c			\
			term_params.c			\
			init.c				\
			pre_parser.c)

L_OBJS		= $(L_SRCS:.c=.o)

P_OBJS		= $(P_SRCS:.c=.o)

all: $(AR_NAME) $(P_NAME)
	@echo "Compiled!"

$(AR_NAME): $(L_OBJS)
	@ar rc $(L_NAME) $(L_OBJS)
	@ranlib $(L_NAME)
	@cp lib/my/my.h inc
	@mv $(L_NAME) lib

$(P_NAME): $(P_OBJS)
	@$(CC) -o $(P_NAME) -Llib $(P_OBJS) -lmy


clean:
	@rm -f $(L_OBJS) $(P_OBJS)

fclean: clean
	@rm -f $(addprefix lib/, $(L_NAME)) $(P_NAME)

re: fclean all
