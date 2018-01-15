FLAGS := -fPIC -O3 -g -Wall -Werror
CC := gcc
NAME := sharedlib

make: $(NAME).so

$(NAME).so: $(NAME).o
	$(CC) -shared -Wl,-soname,$(NAME).so $^ -o $@

clean:
	$(RM) *.o *.so*
