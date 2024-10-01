# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 11:49:04 by jeguerin          #+#    #+#              #
#    Updated: 2024/10/01 11:49:06 by jeguerin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'executable
NAME = fixed

# Compilateur
CXX := c++ # or g++

# Options de compilation
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

#Liste des fichiers source.
SRCS = main.cpp  newFixed.cpp \

OBJS = $(SRCS:.cpp=.o)

# Regle par defaut pour l'executable
all: author $(NAME)

# Regles pour afficher l'auteur et le projet.
author:
	@echo "Authors : jeguerin\n"
	@echo "Project : My awesome phoneBook \n"

# Regle pour creer l'executable en liant les objets.
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Règle pour générer les fichiers objets à partir des fichiers sources
#%.o: %.cpp
#$(CXX) $(CXXFLAGS) -o $@ -c $<

# Regle pour nettoyer les fichiers objets.
clean:
	$(RM) $(OBJS)

# Regle pour nettoyer les fichiers objets et l'executable.
fclean: clean
	$(RM) $(NAME)

# Regle pour reconstruire le projet (clean, puis all)
re: author fclean all

# Declarer les regles comme des cibles .phony pour eviter des conflits avec
# des fichiers du meme nom.
.PHONY: all clean fclean re
