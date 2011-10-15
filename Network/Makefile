NAME = sniff
CFLAGS += -Wall -Wextra -O3 `pcap-config --cflags` `dnet-config --cflags`
LDLIBS += `pcap-config --libs` `dnet-config --libs`

SRC = $(NAME).c handle_packet.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ): $(NAME).h

clean:
	rm -r $(OBJ)

distclean:
	rm -f $(NAME)

re: distclean all
	
