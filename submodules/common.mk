# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    common.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 07:14:16 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/14 02:50:24 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef NAME
	$(error NAME is not set)
endif
ifndef SRC
	$(error SRC is not set)
endif
ifndef SRC_DIR
	$(error SRC_DIR is not set)
endif
ifndef OBJ_DIR
	$(error OBJ_DIR is not set)
endif
ifndef OBJ
	$(error OBJ is not set)
endif

SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ			:=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_FILES		:=	$(SRC:$(SRC_DIR)/%.c=$(D_DIR)/%.d)

DEPS_INC	:=	$(DEPS:%=../%/include)

mutator		:=	$(shell echo "../$(NAME)/lib$(NAME).a")
DEPENDENCIES		:=	$(foreach dep,$(DEPS),$(call apply_shell_cmd,$(dep)))	

all: $(OUTPUT)

-include $(DEP_FILES)

$(DEP_FILES): $(DEPS_DIR)/%.d: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	@printf "Generating dependencies for $<\n"
	$(CC) $(CFLAGS) -MM $< -MT $(OBJ_DIR)/$*.o -MF $@

$(OUTPUT): $(DEPS) $(OBJ)
ifneq ($(IS_EXEC),1)
	$(LD) $(LDFLAGS) $(OUTPUT) $(OBJ) 
else
	$(LD) $(LDFLAGS) $(OBJ) -o $(OUTPUT) $(DEPS:%=-Wl,--whole-archive %) 
endif
	@printf "\033[32m$(OUTPUT) created\033[0m\n"

$(DEPS):
	@printf "> Making '$@'\n"
	make -C ../$@ all CACHE_DIR="$(CACHE_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "\tCompiling $<\n"
	$(CC) $(CFLAGS) -c $< -o $@

clean_deps:
	@printf "Cleaning dependencies\n"
	@for dep in $(DEPS); do \
		make -C ../$$dep clean CACHE_DIR="$(CACHE_DIR)"; \
	done

clean: clean_deps
	rm -rf $(CACHE_DIR)
	
fclean_deps:
	@printf "Fcleaning dependencies\n"
	@for dep in $(DEPS); do \
		make -C ../$$dep fclean CACHE_DIR="$(CACHE_DIR)"; \
	done

fclean: fclean_deps clean
	@printf "\033[31m$(OUTPUT) cleaned\033[0m\n"
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re
